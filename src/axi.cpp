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
        channel->write_trigger(1);
        wait();
        channel->write_trigger(0);
        wait(5, SC_SEC);
        channel->write_reset(1);
        wait();
        channel->write_reset(0);

    }
}

void axi::wait_cycle(int w){
    for (int i; i<w; w++){
        wait();
    }
}