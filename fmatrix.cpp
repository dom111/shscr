#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>


using namespace std;

int main()
{
	system("clear");

	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
	srand(time(NULL));

	while(true)
	{
		for(int i = 0; i < size.ws_col-1; i++)
		{
			cout << "\e[92m" << rand()%2;
		}
	
		cout << "\n";
		fflush(stdout);
		usleep(50 * 1000);
	}
}
