#include<systemc.h>
#include "../include/axi_top.h"
//#include "../include/top.h"

int sc_main(int argc, char* argv[]) {
	axi_top axi_top("axi_top");
	sc_start(10, SC_SEC);

	cout << "Finished." << endl;
	return 0;
}