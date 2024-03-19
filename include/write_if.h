#ifndef __WRITE_IF__
#define __WRITE_IF__

#include<systemc.h>

class write_if : public sc_interface {
    public:
    virtual void write(sc_bv<8>) = 0;
    virtual void reset() = 0;
};

#endif