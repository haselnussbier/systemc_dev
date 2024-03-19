#include<systemc.h>
#include "../include/axi_top.h"
//#include "../include/top.h"

int sc_main(int argc, char* argv[]) {
	sc_set_time_resolution(100, SC_MS);
	axi_top axi_top("axi_top");
	sc_start(400, SC_SEC);

	cout << "Finished." << endl;
	return 0;
}