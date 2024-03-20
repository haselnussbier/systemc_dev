#include<systemc.h>
#include "../include/axi_top.h"

int sc_main(int argc, char* argv[]) {
	
	axi_top axi_top("axi_top");

	sc_start(50, SC_SEC);
	cout << "Finished." << endl;
	return 0;
}