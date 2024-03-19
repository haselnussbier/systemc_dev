#ifndef __FIFO__
#define __FIFO__

#include<systemc.h>
#include "write_if.h"
#include "read_if.h"

class fifo : public sc_channel, public write_if, public read_if {
    public:
        fifo() : num_elements(0), first(0) {}

        void write(sc_bv<8> TDATA) {
            if (num_elements == max_elements) {
                wait(read_event);
            } 

            mem[(first + num_elements) % max_elements] = TDATA;
            ++num_elements;
            write_event.notify();
        }

        void read(sc_bv<8>& TDATA) {
            if (num_elements==0) {
                wait(write_event);
            }

            TDATA = mem[first];
            -- num_elements;
            first = (first + 1) % max_elements;
            read_event.notify();
        }

        void reset() {num_elements = first = 0;}

        int num_available() {return num_elements;}

    private:
        enum e {max_elements = 10};
        sc_bv<8> mem[max_elements];
        int num_elements, first;
        sc_event write_event, read_event;
};

#endif