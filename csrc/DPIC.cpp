
#include "difftest.hpp"
// DPIC函数
// DPIC函数

std::unordered_map<uint32_t, uint32_t> imem;
std::unordered_map<uint32_t, uint32_t> dmem;
std::deque<std::string> bufferPC = {"80000000", "80000000","80000000"};
std::deque<std::string> bufferIN = {"00000000", "00000000","00000000","00000000"};

std::string toHexString(uint32_t value) {
    std::stringstream ss;
    ss << std::hex << std::setw(8) << std::setfill('0') << value;
    return ss.str();
}
extern "C" void write_imem(uint32_t addr, uint32_t data);
extern "C" void handle_ebreak() {
    if(bufferIN[3]=="00100073"){

    if (top->rootp->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[10] != 0) {
        std::cerr << "HIT BAD TRAP " << std::endl;
        std::exit(EXIT_FAILURE);
    } else {
        std::cout << "HIT GOOD TRAP" << std::endl;
        std::exit(EXIT_SUCCESS);
    }
    std::cout << "Program terminated successfully." << std::endl;
    Verilated::gotFinish(true); }
}

extern "C" void initialize_imem(const char* filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string line;
    uint32_t addr = 0x80000000;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        uint32_t instr;
        if (iss >> std::hex >> instr) {
            imem[addr] = instr;
            addr += 4; // 每条指令占4个字节
        }
    }
    infile.close();
}

 void load_imem(const char* filename) {
    // 打开文件
    std::ifstream infile(filename, std::ios::binary);
    if (!infile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        std::exit(EXIT_FAILURE);
    }

    // 获取文件大小
    infile.seekg(0, std::ios::end);
    std::streamsize size = infile.tellg();
    infile.seekg(0, std::ios::beg);

   
    uint32_t addr = 0x80000000;
    uint32_t data;

    // 读取文件并写入内存
    while (infile.read(reinterpret_cast<char*>(&data), sizeof(data))) {
        //std::cout<<std::hex<<addr<<std::endl;
        write_imem(addr, data);
        addr += 4; // 每条指令占4个字节
    }

    // 检查读取文件是否有错误
    if (!infile.eof()) {
        std::cerr << "Error reading file: " << filename << std::endl;
        std::exit(EXIT_FAILURE);
    }

    infile.close();
}

// 读IMEM
extern "C" uint32_t read_imem(uint32_t addr) {
    auto it = imem.find(addr);
    if (it != imem.end()) {
        //std::cout<< "IMEM read success:  address 0x" << std::hex << addr << std::endl;
        //std::cout<< "IMEM read data   :          0x" << std::hex << it->second << std::endl;
        return it->second;
    } else {
        std::cerr << "IMEM read error: invalid address 0x" << std::hex << addr << std::endl;
        return 0; // 或者返回其他错误码
    }
    //contextp->timeInc(2);
}

// 写IMEM
extern "C" void write_imem(uint32_t addr, uint32_t data) {
    imem[addr] = data;
}

// 读DMEM
extern "C" uint32_t read_dmem(uint32_t addr) {
    auto it = imem.find(addr);
    if (it != imem.end()) {
        //std::cout<< "DMEM read success:  address 0x" << std::hex << addr << std::endl;
        //std::cout<< "DMEM read data   :          0x" << std::hex << it->second << std::endl;
        return it->second;
    } else {
        //std::cerr << "DMEM read error: invalid address 0x" << std::hex << addr << std::endl;
        return 0; // 或者返回其他错误码
    }
}

// 写DMEM
extern "C" void write_dmem(uint32_t addr, uint32_t data) {
    dmem[addr] = data;
}

extern "C" void itrace(uint32_t PCF, uint32_t PCD,uint32_t PCE,uint32_t INF,uint32_t IND){
    std::cout<<"==========================================="<<std::endl;
    std::cout << "F:PC : " << std::hex << std::setw(8) << std::setfill('0') << PCF
              << " INS: " << std::hex << std::setw(8) << std::setfill('0') << INF << std::endl;
    std::cout << "D:PC : " << std::hex << std::setw(8) << std::setfill('0') << PCD
              << " INS: " << std::hex << std::setw(8) << std::setfill('0') << IND << std::endl;
    
    bufferPC.pop_back();
    bufferIN.pop_back();
    bufferPC.push_front(toHexString(PCE));
    if(PCE==0){

        
         bufferIN.pop_front();
         bufferIN.push_front(toHexString(0));
         bufferIN.push_front(toHexString(0));
         //bufferIN = {"00000000", "00000000","00000000","00000000"};
    }else{
    bufferIN.push_front(toHexString(IND));
    }
    std::cout << "E:PC : " << std::hex << std::setw(8) << std::setfill('0') << PCE
              << " INS: " << bufferIN[1] << std::endl;
    std::cout<<"W:PC : "<< std::hex << bufferPC[1]<<" INS: "<< std::hex<<bufferIN[2]<<std::endl;
    std::cout<<"M:PC : "<< std::hex << bufferPC[2]<<" INS: "<< std::hex<<bufferIN[3]<<std::endl;
    std::cout<<"==========================================="<<std::endl;
}



