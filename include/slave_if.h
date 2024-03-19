#ifndef __SLAVE_IF__
#define __SLAVE_IF__

#include<systemc.h>

class slave_if : public sc_interface {
    public:
        virtual sc_bv<8> s_read_data() = 0;
        virtual bool s_read_valid() = 0;
        virtual bool s_read_last() = 0;
        virtual void s_write_ready(bool ready) = 0;
};

#endif