#include<systemc.h>
#include "../include/axi_tb_top.h"

int sc_main(int argc, char* argv[]) {
	sc_start(10, SC_SEC);
	axi_tb_top axi_tb_top("axi_tb_top");
	cout << "Finished." << endl;
	return 0;
}