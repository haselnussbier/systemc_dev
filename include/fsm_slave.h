#ifndef __FSM_SLAVE__
#define __FSM_SLAVE__

#include<systemc.h>
#include "slave_if.h"

enum slave_fsm_state{ s_reset, ready, waitForValid};

SC_MODULE(fsm_slave){
    sc_in_clk ACLK;
    sc_in<bool> ARESETn;
    sc_port<slave_if> channel;

    sc_signal<slave_fsm_state> current_state;
    //data out
    sc_signal<int> LENGTH;
    sc_signal<int> COUNTER;



    void get_next_state();

    SC_CTOR(fsm_slave){
        SC_THREAD(get_next_state);
        sensitive << ACLK.pos();
        dont_initialize();
    }
};

#endif