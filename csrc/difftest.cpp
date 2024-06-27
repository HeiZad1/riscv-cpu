#include "difftest.hpp"

#define   nemu2npc 1
#define   npc2nemu 0
#define   first_addr 0x0
#define MEMORY_BASE 0x80000000

extern  char *regs[];

uint32_t buf_reg[32];

typedef struct {
  uint32_t address;
  uint32_t data;
} addr_data_t;

//addr_data_t *buf;



//void difftest_regcpy(void *dut, bool direction);
extern "C" __EXPORT void difftest_regcpy(void *dut, bool direction);
extern "C" __EXPORT void difftest_memcpy(uint32_t addr, uint32_t *buf, size_t n, bool direction);



void difftest(uint64_t n){
    /*
    uint32_t PC = MEMORY_BASE;
    uint32_t inst = imem[MEMORY_BASE];
    std::cout<< std::hex<<PC<< std::hex<<inst<<std::endl;
    addr_data_t buf[n];
    for (int i = 0; i < n; i++) {
        buf[i].address = PC;
        buf[i].data    = inst; 
        PC += 4; 
    }*/
    //difftest_memcpy(MEMORY_BASE,buf,n,npc2nemu);
    
    difftest_exec(n);

    /*
    difftest_regcpy(buf_reg,nemu2npc);
    std::cout << "buf_reg content after difftest_regcpy:" << std::endl;
    for (int i = 0; i < 32; i++) {
        std::cout << std::hex << buf_reg[i] << " ";
    }
     std::cout <<std::endl;
*/
    
    difftest_regcpy(buf_reg,nemu2npc);
    std::cout << std::endl;
    for(int i=0;i<32;i++){
        if(top->rootp->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[i]!=buf_reg[i]){
            std::cout<<"error state at "<< regs[i] <<"npc reg value : "<< std::hex << top->rootp->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[i]
                        <<" nemu reg value: "<<std::hex<< buf_reg[i]<<std::endl;
            
            
        }
            
    }
}

void init_nemu_mem(){
    //size_t t = sizeof(img_file);
    //std::cout<<t;
    

    std::ifstream infile(img_file, std::ios::binary);
    if (!infile.is_open()) {
        std::cerr << "Error opening file: " << img_file << std::endl;
        std::exit(EXIT_FAILURE);
    }

    // 获取文件大小
    infile.seekg(0, std::ios::end);
    std::streamsize size = infile.tellg();
    infile.seekg(0, std::ios::beg);

    uint32_t buf_mem[size];
   
    uint32_t addr = 0x80000000;
    uint32_t data;
    int i=0;

    // 读取文件并写入内存
    while (infile.read(reinterpret_cast<char*>(&data), sizeof(data))) {
        buf_mem[i] = data;
        //addr += 4; // 每条指令占4个字节
        i++;
    }

    // 检查读取文件是否有错误
    if (!infile.eof()) {
        std::cerr << "Error reading file: " << img_file << std::endl;
        std::exit(EXIT_FAILURE);
    }

    infile.close();

    difftest_memcpy(0x80000000,buf_mem,size,npc2nemu);
}
