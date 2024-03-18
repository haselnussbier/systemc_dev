#include "../include/axi_channel.h"

void axi_channel::write(sc_bv<8> TDATA){
    mem = TDATA;
}

sc_bv<8> axi_channel::read(){
    return mem;
}

void axi_channel::reset(){
    mem = "00000000";
}