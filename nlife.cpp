#include <iostream>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
	system("clear");

	system("setterm -cursor off");

	string index[] = {"\033[1A", "\033[1B", "\033[1C", "\033[1D", "\033[1C", "\033[1D"};
	
	srand(time(NULL));

	while(true)
	{
		int x = rand()%6;
		cout << index[x];
		cout << x;
		cout << "\033[1D";
		fflush(stdout);
		usleep(10 * 1000);
	}
}
