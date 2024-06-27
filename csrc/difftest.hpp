#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include "verilated.h"
#include "Vrv32i___024root.h"
#include "Vrv32i.h"
#include <deque>
#include <string>
#include <iomanip> 
 #include "sdb.hpp"

 
#define __EXPORT __attribute__((visibility("default")))

   extern  char *img_file ;

extern "C" __EXPORT void difftest_init(int port);
extern "C" __EXPORT void difftest_exec(uint64_t n);
void difftest(uint64_t n);

extern std::unordered_map<uint32_t, uint32_t> imem;
extern std::unordered_map<uint32_t, uint32_t> dmem;
extern std::deque<std::string> bufferPC ;
extern std::deque<std::string> bufferIN ;

