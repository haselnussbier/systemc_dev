#ifndef __AXI_CHANNEL__
#define __AXI_CHANNEL__

#include<systemc.h>
#include "master_if.h"
#include "slave_if.h"
#include "axi_if.h"

class axi_channel : public sc_channel, public master_if, public slave_if, public axi_if{
    public:
        axi_channel(sc_module_name name = sc_gen_unique_name("AXI")) : sc_channel(name) {}
        SC_HAS_PROCESS(axi_channel);
        void m_write_data(sc_bv<8> data);
        void m_write_valid(bool valid);
        void m_write_last(bool last);
        bool m_read_ready();
        bool m_read_trigger();
        bool m_read_reset();

        sc_bv<8> s_read_data();
        bool s_read_valid();
        bool s_read_last();
        void s_write_ready(bool ready);
        bool s_read_reset();

        void write_reset(bool reset);
        void write_trigger(bool trigger);
        
        sc_bv<8> TDATA;
        bool TVALID;
        bool TLAST;
        bool TREADY;
        bool TRIGGER;
        bool ARESETn;
};

#endif