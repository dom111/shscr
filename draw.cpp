#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>


using namespace std;

int main()
{
	
	system("clear");
	while(true)
	{
		printf("\e[34;44m0");
		fflush(stdout);
		usleep(500 * 1000);
	}
}
