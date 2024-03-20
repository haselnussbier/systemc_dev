#ifndef __MASTER_IF__
#define __MASTER_IF__

#include <systemc.h>
class master_if : public sc_interface{
    public:
        virtual void m_write_data(sc_bv<8> data) = 0;
        virtual void m_write_valid(bool valid) = 0;
        virtual void m_write_last(bool last) = 0;
        virtual bool m_read_ready() = 0;
        virtual bool m_read_trigger() = 0;
        virtual bool m_read_reset() = 0;
};

#endif