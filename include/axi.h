#ifndef __AXI__
#define __AXI__

#include<systemc.h>
#include "axi_if.h"

SC_MODULE(axi){
    sc_in_clk ACLK;
    sc_port<axi_if> channel;

    void stim();

    SC_CTOR(axi){
        cout << "axi" << endl;
        SC_THREAD(stim);
        sensitive << ACLK.pos();
        dont_initialize();
    }
};

#endif