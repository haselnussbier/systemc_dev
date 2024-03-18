#ifndef __AXI_TOP__
#define __AXI_TOP__

#include<systemc.h>
#include "master.h"
#include "slave.h"
#include "axi_channel.h"

SC_MODULE(axi_top){
    
    master *master0;
    slave *slave0;

    sc_clock clk;
    axi_channel axi_channel0;
    sc_signal<bool> TVALID;
    sc_signal<bool> TREADY;

    SC_CTOR(axi_top){
        master0 = new master("master");
        master0->clk(clk);
        master0->out(axi_channel0);
        master0->TVALID(TVALID);
        master0->TREADY(TREADY);
    
        slave0 = new slave("slave");
        slave0->clk(clk);
        slave0->in(axi_channel0);
        slave0->TVALID(TVALID);
        slave0->TREADY(TREADY);
    }
};

#endif