#ifndef __SLAVE_IF__
#define __SLAVE_IF__

#include<systemc.h>

class slave_if : public sc_interface {
    public:
        virtual sc_bv<8> read() = 0;
};

#endif