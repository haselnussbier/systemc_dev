#include "../include/axi.h"

void axi::stim(){
    while(true){
        wait();
        channel->write_reset(1);
        wait();
        channel->write_reset(0);
        wait();
        channel->write_trigger(1);
        wait();
        channel->write_trigger(0);
        wait(20, SC_SEC);

    }
}