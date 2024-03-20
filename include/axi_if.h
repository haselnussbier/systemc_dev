#ifndef __AXI_IF__
#define __AXI_IF__

#include<systemc.h>

class axi_if : public sc_interface {
    public:
        virtual void write_reset(bool reset) = 0;
        virtual void write_trigger(bool trigger) = 0;
};

#endif