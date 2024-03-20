#ifndef __AXI_TOP__
#define __AXI_TOP__

#include<systemc.h>
#include "axi_channel.h"
#include "fsm_master.h"
#include "fsm_slave.h"
#include "fsm_master.h"
#include "fsm_slave.h"
#include "axi.h"

SC_MODULE(axi_top){
    sc_clock clk;
    
    fsm_master master;
    fsm_slave slave;
    axi axi0;
    axi_channel channel;

    SC_CTOR(axi_top) : clk("clk", 1, SC_SEC), master("master"), slave("slave"), axi0("axi0"), channel("channel") {
        cout << "axi_top constructor" << endl;
        master.ACLK(clk);
        master.channel(channel);

        slave.ACLK(clk);
        slave.channel(channel);

        axi0.ACLK(clk);
        axi0.channel(channel);
    }
};

#endif