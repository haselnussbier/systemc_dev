#ifndef __AXI_CHANNEL__
#define __AXI_CHANNEL__

#include<systemc.h>
#include "master_if.h"
#include "slave_if.h"

class axi_channel : public sc_channel, public master_if, public slave_if {
    public:
        void write(sc_bv<8> TDATA);
        sc_bv<8> read();
        void reset();

    private:
        sc_bv<8> mem;
        
};

#endif