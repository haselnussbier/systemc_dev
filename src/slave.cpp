#include "../include/slave.h"

void slave::slave_thread(){
    while(1){
        wait();
        if (TVALID.read() == true){
            if (rand() % 5 == 4){
                TREADY.write(0);
                TDATA = in->read();
            }
        }
    }
}