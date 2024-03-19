#include "../include/master.h"

void master::master_thread(){
    cout << "master thread" << endl;
    out->reset();
    wait();
    while(1){
        wait();
        TDATA = "10101010";
        out->write(TDATA);
        TVALID.write(1);
        wait(TREADY);
    }
}