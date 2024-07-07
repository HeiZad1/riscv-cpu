#include "Vaxi_slaver.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>

#define SIM_TIME 100

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    Vaxi_slaver* top = new Vaxi_slaver;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    top->ARESETN = 0;
    top->ACLK = 0;

    for (int i = 0; i < SIM_TIME; i++) {
        if (i > 2) top->ARESETN = 1;  // De-assert reset after some time

        // Toggle clock
        top->ACLK = !top->ACLK;
        top->eval();

        // Add test stimuli
        top->ren = (i > 10 && i < 20);  // Example stimulus
        top->ARADDR = (i > 10 && i < 20) ? 0x1234 : 0x0;

        top->wen = (i > 30 && i < 40);
        top->AWADDR = (i > 30 && i < 40) ? 0x5678 : 0x0;

        top->WDATA = (i > 30 && i < 40) ? 0xABCD : 0x0;
        //top->WVALID = (i > 30 && i < 40);

        // Evaluate the model
        top->eval();
        tfp->dump(i);
    }

    tfp->close();
    delete top;
    return 0;
}
