#ifndef __AXI_TOP__
#define __AXI_TOP__

#include<systemc.h>
#include "axi_channel.h"
#include "fsm_master.h"
#include "fsm_slave.h"
#include "fsm_master.h"
#include "fsm_slave.h"

SC_MODULE(axi_top){
    sc_in_clk ACLK;
    sc_in<bool> ARESETn;
    sc_in<bool> TRIGGER;
    sc_in_clk ACLK;
    sc_in<bool> ARESETn;
    sc_in<bool> TRIGGER;

    fsm_master master;
    fsm_slave slave;
    axi_channel channel;
    fsm_master master;
    fsm_slave slave;
    axi_channel channel;

    SC_CTOR(axi_top) : master("master"), slave("slave"), channel("channel") {
        cout << "axi_top constructor" << endl;
        master.ACLK(ACLK);
        master.ARESETn(ARESETn);
        master.channel(channel);
        master.TRIGGER(TRIGGER);

        slave.ACLK(ACLK);
        slave.ARESETn(ARESETn);
        slave.channel(channel);
    }
};

#endif