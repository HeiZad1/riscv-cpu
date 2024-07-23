  #include "VysyxSoCFull.h"
  #include "verilated.h"
  #include "VysyxSoCFull__Dpi.h"
  #include "VysyxSoCFull___024root.h"
  #include <iostream>
  #include <getopt.h>
  #include <cassert>
  #include "sdb.hpp"
 #include "verilated_vcd_c.h"
 #include "difftest.hpp"

    
  
    #define BLUE    "\033[34m"
    #define RESET_VECTOR 0x80000000
    #define RESET   "\033[0m"

 

    void difftest(uint64_t n);
    void init_nemu_mem();

    static char *log_file = NULL;//sasas
    static char *diff_so_file = NULL;
     char *img_file = NULL;
    static int difftest_port = 1234;
    VerilatedContext* contextp = nullptr;
    VerilatedVcdC* tfp = nullptr;
    VysyxSoCFull* top = nullptr;
    
    extern "C" void initialize_imem(const char* filename);
    extern "C" void handle_ebreak();
    extern "C" void flash_read(int32_t addr, int32_t *data) ;
    extern "C" void mrom_read(int32_t addr, int32_t *data) ;
    

    //extern "C" void write_imem(uint32_t addr, uint32_t data);
     void load_mrom(const char* filename);
    

    std::deque<bool> bufferStall = {0,0,0,0};
    std::deque<bool> bufferJamp = {0,0,0,0,0};
    //std::deque<bool> bufferAxi = {0,0,0,0};

    

    static int parse_args_npc(int argc, char *argv[]) {
    const struct option table[] = {
    {"batch"    , no_argument      , NULL, 'b'},
    {"log"      , required_argument, NULL, 'l'},
    {"diff"     , required_argument, NULL, 'd'},
    {"port"     , required_argument, NULL, 'p'},
    {"help"     , no_argument      , NULL, 'h'},
    {0          , 0                , NULL,  0 },
    
  };
    int o;
    while ( (o = getopt_long(argc, argv, "-bhl:d:p:", table, NULL)) != -1) {
        switch (o) {
            case 'b': ; break;
            case 'p': sscanf(optarg, "%d", &difftest_port); break;
            case 'l': log_file = optarg; break;
            case 'd': diff_so_file = optarg; break;
            case 1: if (img_file == NULL) {
                  img_file = optarg;
                  } 
              
        
        break;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\n");
        exit(0);
    }
    }
  return 0;
}

    void cpu_exec(uint64_t n){
        uint64_t t = n;
        for(;n>0;n --){   
             
        top->clock = !top->clock;
        top->eval();
        tfp->dump(contextp->time());
        contextp->timeInc(1);

        top->clock = !top->clock;
        top->eval();
        tfp->dump(contextp->time());
        contextp->timeInc(1);

        bufferStall.pop_back();
        bufferJamp.pop_back();
        //bufferAxi.pop_back();
        bufferStall.push_front(top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rv__DOT__hu__DOT__lwStall);
        bufferJamp.push_front(top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rv__DOT__PCSrcE);
        //bufferAxi.push_front(top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__axi_m_if__DOT__r_stallRead);
/*流水线暂停
        if(bufferJamp[4])
          //std::cout<<bufferJamp[2]<<std::endl;
          n+=2;
        if(bufferStall[3])
         //std::cout<<bufferStall[1]<<std::endl;
          n+=1;*/
        }
  
        
    }

 int main(int argc, char** argv) {
    /*
    if (argc < 1) {
        std::cerr << "Usage: " << argv[0] << " <elf_file>" << std::endl;
        return EXIT_FAILURE;
    }*/
    //const char* file_path = argv[1];
    
    contextp = new VerilatedContext;  // 创建一个VerilatedContext对象，用于管理仿真上下文
    contextp->commandArgs(argc, argv);                  // 解析命令行参数

    top = new VysyxSoCFull{contextp};

    tfp = new VerilatedVcdC;
    Verilated::traceEverOn(true);
    top->trace(tfp, 99);
    tfp->open("ysyxSoCFull.vcd");
    
                          // 创建顶层模块的实例
     parse_args_npc(argc,argv);
     std::cout<<BLUE<<img_file<<std::endl;
     load_mrom(img_file);
     //initialize_imem("riscvtest.txt");
     top->clock = 0;
     top->reset = 1;
     int reset_cycles = 30; 
     while (reset_cycles > 0) {
        top->clock = !top->clock;
        top->eval();
        contextp->timeInc(1);
        tfp->dump(contextp->time()); 
        reset_cycles--;
        } 
            top->clock = !top->clock;
            top->reset = 0;  // 结束复位
        

    // 仿真主循环
    //init_nemu_mem();
    #ifdef difftest1
    difftest_init(1);
    init_nemu_mem();
    cpu_exec(17);
    //difftest();
    #endif
    sdb_mainloop();


    tfp->close();
    delete tfp;

    top->final();

    delete top;                                         // 释放顶层模块实例的内存
    delete contextp;                                    // 释放仿真上下文的内存
    return 0;                                           // 返回0，表示程序成功终止
}






