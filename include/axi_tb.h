#ifndef __AXI_TB__
#define __AXI_TB__

#include<systemc.h>

SC_MODULE(axi_tb){
    sc_in_clk ACLK;

    sc_out<bool> ARESETn;
    sc_out<bool> TRIGGER;

    void tb_stim();

    SC_CTOR(axi_tb){
        SC_THREAD(tb_stim);
        sensitive << ACLK.pos();
        dont_initialize();
    }
};

#endif