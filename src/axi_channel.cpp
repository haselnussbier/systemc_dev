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
    return TREADY;
}

bool axi_channel::m_read_trigger(){
    return TRIGGER;
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

void axi_channel::write_reset(bool reset){
    ARESETn = reset;
}

void axi_channel::write_trigger(bool trigger){
    TRIGGER = trigger;
}

bool axi_channel::m_read_reset(){
    return ARESETn;
}

bool axi_channel::s_read_reset(){
    return ARESETn;
}