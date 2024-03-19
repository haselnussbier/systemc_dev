#include<systemc.h>
#include "../include/axi_top.h"
#include "../include/top.h"

int sc_main(int argc, char* argv[]) {
  top top("top");
  sc_start();
  return 0;
}