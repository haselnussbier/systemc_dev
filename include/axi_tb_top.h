#ifndef __AXI_TB_TOP__
#define __AXI_TB_TOP__

#include<systemc.h>
#include "axi_top.h"
#include "axi_tb.h"

SC_MODULE(axi_tb_top){
    sc_clock clk;

    sc_signal<bool> reset;
    sc_signal<bool> trigger;

    axi_top axi_top0;
    axi_tb axi_tb0;

    SC_CTOR(axi_tb_top) : clk("clk", 1, SC_SEC), axi_top0("axi_top0"), axi_tb0("axi_tb0") {
        axi_top0.ACLK(clk);
        axi_top0.ARESETn(reset);
        axi_top0.TRIGGER(trigger);

        axi_tb0.ACLK(clk);
        axi_tb0.ARESETn(reset);
        axi_tb0.TRIGGER(trigger);
    }
};

#endif