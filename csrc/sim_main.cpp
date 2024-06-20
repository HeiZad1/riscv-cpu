  #include "Vrv32i.h"
  #include "verilated.h"
  #include "Vrv32i__Dpi.h"
  #include "Vrv32i___024root.h"
  #include <iostream>
  #include <getopt.h>
  #include <cassert>
  #include "sdb.h"
    
  
    #define BLUE    "\033[34m"
    #define RESET_VECTOR 0x80000000
    #define RESET   "\033[0m"

    static char *log_file = NULL;
    static char *diff_so_file = NULL;
    static char *img_file = NULL;
    static int difftest_port = 1234;
    
    extern "C" void initialize_imem(const char* filename);
    extern "C" void handle_ebreak();
    extern "C" void write_imem(uint32_t addr, uint32_t data);
    extern "C" void load_imem(const char* filename);

    

    static int parse_args(int argc, char *argv[]) {
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


 int main(int argc, char** argv) {
    /*
    if (argc < 1) {
        std::cerr << "Usage: " << argv[0] << " <elf_file>" << std::endl;
        return EXIT_FAILURE;
    }*/
    //const char* file_path = argv[1];

    VerilatedContext* contextp = new VerilatedContext;  // 创建一个VerilatedContext对象，用于管理仿真上下文
    contextp->commandArgs(argc, argv);                  // 解析命令行参数
    
    
     Vrv32i* top = new Vrv32i{contextp};                     // 创建顶层模块的实例
     //parse_args(argc,argv);
     //std::cout<<BLUE<<img_file<<std::endl;
     //load_imem(img_file);
     initialize_imem("riscvtest.txt");
     top->clk = 0;
     top->reset = 1;
     int reset_cycles = 10; 
    // 仿真主循环
    while (!contextp->gotFinish()) {
        top->clk = !top->clk; 
        if (reset_cycles > 0) {
            reset_cycles--;
        } else {
            top->reset = 0;  // 结束复位
        }
        top->eval(); 
        contextp->timeInc(1);
       
       
    }

    delete top;                                         // 释放顶层模块实例的内存
    delete contextp;                                    // 释放仿真上下文的内存
    return 0;                                           // 返回0，表示程序成功终止
}
