#ifndef __FSM_MASTER__
#define __FSM_MASTER__

#include<systemc.h>
#include "master_if.h"

enum master_fsm_state {m_reset, waitForTriggerHigh, waitForTriggerLow, waitForReady, waitForSlave};

SC_MODULE(fsm_master){
    sc_in_clk ACLK;
    sc_port<master_if> channel;

    sc_signal<master_fsm_state> current_state;
    int COUNTER;
    int LENGTH = 5;


    void get_next_state();
    sc_bv<8> generate_data();

    SC_CTOR(fsm_master){
        cout << "fsm_master constructor" << endl;
        SC_THREAD(get_next_state);
        sensitive << ACLK.pos();
        dont_initialize();
    }
};

#endif