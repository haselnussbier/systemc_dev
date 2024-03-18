#ifndef __SLAVE__
#define __SLAVE__

#include<systemc.h>
#include "slave_if.h"

SC_MODULE(slave){
    sc_in_clk clk;

    sc_out<bool> TREADY;

    sc_in<bool> TVALID;
    //sc_in<bool> TLAST;
    //sc_in<bool> TKEEP;

    

    sc_port<slave_if> in;

    sc_bv<8> TDATA;
    
    void slave_thread();

    SC_CTOR(slave){
        SC_THREAD(slave_thread);
        sensitive << clk;
    };
};

#endif