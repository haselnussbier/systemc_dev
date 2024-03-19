#include "../include/axi_channel.h"

void axi_channel::m_write_data(sc_bv<8> data){
    TDATA = data;
}

void axi_channel::m_write_valid(bool valid){
    TVALID = valid;
}

void axi_channel::m_write_last(bool last){
    TLAST = last;
}

bool axi_channel::m_read_ready(){
    return TREADY.read();
}

void axi_channel::m_reset(){
    TDATA = "00000000";
    TVALID = 0;
    TLAST = 0;
    TREADY = 0;
}

sc_bv<8> axi_channel::s_read_data(){
    return TDATA;
}

bool axi_channel::s_read_valid(){
    return TVALID;
}

bool axi_channel::s_read_last(){
    return TLAST;
}

void axi_channel::s_write_ready(bool ready){
    TREADY = ready;
}