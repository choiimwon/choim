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

	cycle = ispRunBinaryFile(device, "./AprioriImplementation", "input1", "output.txt");
	system("cat output.txt");
										
	printf("\nISP cycle = %d\n", cycle);
											
}

