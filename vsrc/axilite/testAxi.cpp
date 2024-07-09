#include "VaxiTop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>

#define SIM_TIME 100

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    VaxiTop* top = new VaxiTop;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    top->rst = 1;
    top->clk = 0;

    for (int i = 0; i < SIM_TIME; i++) {
        if (i > 2) top->rst = 0;  // De-assert reset after some time

        // Toggle clock
        top->clk = !top->clk;
        top->eval();

        // Add test stimuli
        top->ren = (i > 10 && i < 50);  // Example stimulus
        top->addr_m = (i > 10 && i < 50) ? 0x1234 : 0x0;
        /*
        top->wen = (i > 30 && i < 40);
        top->addr_m = (i > 30 && i < 40) ? 0x5678 : 0x0;

        top->write_data_m = (i > 30 && i < 40) ? 0xABCD : 0x0;
        //top->WVALID = (i > 30 && i < 40);
        */
        // Evaluate the model
        top->eval();
        tfp->dump(i);
    }

    tfp->close();
    delete top;
    return 0;
}
