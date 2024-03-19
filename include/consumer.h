#ifndef __CONSUMER__
#define __CONSUMER__

#include<systemc.h>
#include "read_if.h"

class consumer : public sc_module {
    public:
        sc_port<read_if> in;

        SC_CTOR(consumer){
            SC_THREAD(main);
        }

        void main() {
            sc_bv<8> TDATA;
            while(true) {
                in->read(TDATA);
            }
        }
}; 

#endif