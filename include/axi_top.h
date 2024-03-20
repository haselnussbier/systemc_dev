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
    sc_trace_file *tracefile;

    SC_CTOR(axi_top) : clk("clk", 1, SC_SEC), master("master"), slave("slave"), axi0("axi0"), channel("channel") {
        cout << "axi_top constructor" << endl;
        master.ACLK(clk);
        master.channel(channel);

        slave.ACLK(clk);
        slave.channel(channel);

        axi0.ACLK(clk);
        axi0.channel(channel);

        tracefile = sc_create_vcd_trace_file("tracefile");
        sc_trace(tracefile, clk, "ACLK");
        sc_trace(tracefile, master.current_state, "master state");
        sc_trace(tracefile, slave.current_state, "slave state");
        sc_trace(tracefile, channel.ARESETn, "ARESETn");
        sc_trace(tracefile, channel.TRIGGER, "TRIGGER");
        sc_trace(tracefile, channel.TDATA, "TDATA");
        sc_trace(tracefile, channel.TVALID, "TVALID");
        sc_trace(tracefile, channel.TREADY, "TREADY");
        sc_trace(tracefile, channel.TLAST, "TLAST");

    }
};

#endif