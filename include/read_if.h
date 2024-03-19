#ifndef __READ_IF__
#define __READ_IF__

#include<systemc.h>

class read_if : public sc_interface {
    public:
        virtual void read (sc_bv<8> &) = 0;
        virtual int num_available() = 0; 
};

#endif