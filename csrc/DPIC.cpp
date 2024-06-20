#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include "verilated.h"
#include "Vrv32i___024root.h"
#include "Vrv32i.h"

std::unordered_map<uint32_t, uint32_t> imem;
std::unordered_map<uint32_t, uint32_t> dmem;

// DPIC函数
// DPIC函数

extern "C" void write_imem(uint32_t addr, uint32_t data);
extern "C" void handle_ebreak() {
    /*
    if (a0_value != 0) {
        std::cerr << "Error: a0 register value is " << a0_value << std::endl;
        std::exit(EXIT_FAILURE);
    } else {
        std::cout << "Program terminated successfully." << std::endl;
        std::exit(EXIT_SUCCESS);
    }*/
    std::cout << "Program terminated successfully." << std::endl;
    Verilated::gotFinish(true); 
}

extern "C" void initialize_imem(const char* filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string line;
    uint32_t addr = 0;
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
/*
extern "C" void load_imem(const char* filename) {
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

   
    uint32_t addr = 0;
    uint32_t data;

    // 读取文件并写入内存
    while (infile.read(reinterpret_cast<char*>(&data), sizeof(data))) {
        write_imem(addr, data);
        addr += 4; // 每条指令占4个字节
    }

    // 检查读取文件是否有错误
    if (!infile.eof()) {
        std::cerr << "Error reading file: " << filename << std::endl;
        std::exit(EXIT_FAILURE);
    }

    infile.close();
}*/

// 读IMEM
extern "C" uint32_t read_imem(uint32_t addr) {
    auto it = imem.find(addr);
    if (it != imem.end()) {
        std::cout<< "IMEM read success:  address 0x" << std::hex << addr << std::endl;
        std::cout<< "IMEM read data   :          0x" << std::hex << it->second << std::endl;
        return it->second;
    } else {
        std::cerr << "IMEM read error: invalid address 0x" << std::hex << addr << std::endl;
        return 0; // 或者返回其他错误码
    }
}

// 写IMEM
extern "C" void write_imem(uint32_t addr, uint32_t data) {
    imem[addr] = data;
}

// 读DMEM
extern "C" uint32_t read_dmem(uint32_t addr) {
    auto it = dmem.find(addr);
    if (it != dmem.end()) {
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