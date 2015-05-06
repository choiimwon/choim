#include <stdio.h>
#include <isp.h>
#include <stdlib.h>
 
int main(int argc, const char* argv[])
{
      isp_device_id device;
   FILE* ifp;
   int n;
   char buffer[1024];
   int cycle;
#ifndef PAR
	cycle = ispRunBinaryFile(device,"./main_isp", "main_isp.cpp", "output.txt");
#else
	cycle = ispRunBinaryFile(device,"./main_par_isp", "main_par_isp", "output.txt");
#endif	
	system("cat output.txt");
	 
	printf("\nISP cycle = %d\n", cycle);
	 
}

