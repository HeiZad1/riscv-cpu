#include <verilated.h>
#include "VysyxSoCFull.h"
#include "verilated_vcd_c.h"
#include <deque>
#include <iomanip> 
#include <iostream>
#include <cstdlib>
#include <cstdint>



// Define a simulation time
vluint64_t sim_time = 0;
std::deque<std::string> bufferPC = {"80000000", "80000000","80000000"};
std::deque<std::string> bufferIN = {"00000000", "00000000","00000000","00000000"};

extern "C" void flash_read(int32_t addr, int32_t *data) { assert(0); }
extern "C" void mrom_read(int32_t addr, int32_t *data) { *data =0x00100073; }
extern "C" void handle_ebreak();
extern "C" void itrace(uint32_t PCF, uint32_t PCD,uint32_t PCE,uint32_t INF,uint32_t IND);

int main(int argc, char **argv, char **env) {
    // Initialize Verilators variables
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    // Create an instance of the top module
    VysyxSoCFull* top = new VysyxSoCFull;

    // If you want waveform tracing
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);  // Trace 99 levels of hierarchy
    tfp->open("ysyxSoCFull.vcd");

    // Initialize simulation inputs
    top->clock = 0;
    top->reset = 1;

    // Run the simulation
    while (!Verilated::gotFinish() && sim_time < 200) {

        if (sim_time == 20) {
            top->reset = 0;  // Deassert reset
        }

        // Toggle the clock
        top->clock = !top->clock;

        // Evaluate the model
        top->eval();

        // Dump trace data for this cycle
        tfp->dump(sim_time);

        // Advance simulation time
        sim_time++;
    }

    // Final model cleanup
    top->final();

    // Close the waveform file
    tfp->close();

    // Cleanup
    delete top;
    delete tfp;

    return 0;
}

std::string toHexString(uint32_t value) {
    std::stringstream ss;
    ss << std::hex << std::setw(8) << std::setfill('0') << value;
    return ss.str();
}

extern "C" void handle_ebreak() {
    if(bufferIN[3]=="00100073"){
/*
    if (top->rootp->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[10] != 0) {
        std::cerr << "HIT BAD TRAP " << std::endl;
        std::exit(EXIT_FAILURE);
    } else {
        std::cout << "HIT GOOD TRAP" << std::endl;
        std::exit(EXIT_SUCCESS);
    }
    std::cout << "Program terminated successfully." << std::endl;*/
    Verilated::gotFinish(true); }
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

