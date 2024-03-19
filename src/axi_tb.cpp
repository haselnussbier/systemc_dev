#include "../include/axi_tb.h"

void axi_tb::tb_stim(){
    wait();
    ARESETn.write(1);
}