#include<systemc.h>
#include "../include/axi_top.h"
//#include "master.h"
//#include "slave.h"

int sc_main(int argc, char* argv[]) {
  
  //Master master("master");
  //Slave slave("slave");
  //tb.master(master);
  //tb.slave(slave);
  axi_top axi_top0("axi_top0");
  sc_start();
  return 0;
}