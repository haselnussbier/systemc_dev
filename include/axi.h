#ifndef __AXI__
#define __AXI__

#include<systemc.h>
#include "axi_if.h"

SC_MODULE(axi){
    sc_in_clk ACLK;
    sc_port<axi_if> channel;

    void stim();
    void wait_cycle(int w);

    SC_CTOR(axi){
        cout << "axi" << endl;
        SC_THREAD(stim);
        sensitive << ACLK;
        dont_initialize();
    }
};

#endif