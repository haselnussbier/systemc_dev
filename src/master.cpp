#include "../include/master.h"

void master::master_thread(){
    while(1){
        wait();
        TDATA = "10101010";
        TVALID.write(1);
        wait(TREADY);
        out->write(TDATA);
        TVALID.write(0);
    }
}