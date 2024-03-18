#ifndef __MASTER_IF__
#define __MASTER_IF__

#include <systemc.h>

class master_if : public sc_interface{
    public:
        virtual void write(sc_bv<8> TDATA) = 0;
        virtual void reset() = 0;
};

#endif