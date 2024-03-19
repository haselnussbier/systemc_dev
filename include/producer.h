#ifndef __PRODUCER__
#define __PRODUCER__

#include<systemc.h>
#include "write_if.h"

class producer : public sc_module {
    public:
        sc_port<write_if> out;

        SC_CTOR(producer) {
            SC_THREAD(main);
        }

        void main() {
            sc_bv<8> TDATA = "11111111";
            int counter = 0;
            while (true)
            {
                out->write(TDATA);
                ++ counter;

                if(counter == 10){
                    out->reset();
                }
            }
             
        }
};

#endif