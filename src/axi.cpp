#include "../include/axi.h"

void axi::stim(){
    channel->write_reset(1);
    wait();
    channel->write_reset(0);
    wait();
    channel->write_trigger(1);
    wait();
    channel->write_trigger(0);
    wait_cycle(20);
}

void axi::wait_cycle(int w){
    for (int i; i<w; w++){
        wait();
    }
}