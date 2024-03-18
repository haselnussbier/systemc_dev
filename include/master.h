#ifndef __MASTER__
#define __MASTER__

#include<systemc.h>
#include "master_if.h"

SC_MODULE(master){
    sc_in_clk clk;
    sc_in<bool> TREADY;

    sc_out<bool> TVALID;
    //sc_out<bool> TLAST;
    //sc_out<bool> TKEEP;
    sc_bv<8> TDATA;

    sc_port<master_if> out;

    void master_thread();

    SC_CTOR(master){
        SC_THREAD(master_thread);
        sensitive << clk;
    };
};

#endif