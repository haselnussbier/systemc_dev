#ifndef __AXI_CHANNEL__
#define __AXI_CHANNEL__

#include<systemc.h>
#include "master_if.h"
#include "slave_if.h"

class axi_channel : public sc_channel, public master_if, public slave_if {
    public:
        SC_HAS_PROCESS(axi_channel);
        axi_channel(sc_module_name name = sc_gen_unique_name("AXI")) : sc_channel(name) {}
        void m_write_data(sc_bv<8> data);
        void m_write_valid(bool valid);
        void m_write_last(bool last);
        bool m_read_ready();
        void m_reset();

        sc_bv<8> s_read_data();
        bool s_read_valid();
        bool s_read_last();
        void s_write_ready(bool ready);
    private:
        sc_signal<sc_bv<8>> TDATA;
        sc_signal<bool> TVALID;
        sc_signal<bool> TLAST;
        sc_signal<bool> TREADY;
};

#endif