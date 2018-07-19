#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
	
	srand(time(NULL));	

	while(true)
	{
		int col = size.ws_col-1;
		cout << string(rand()%col, ' ');
		cout << ".\n";
		fflush(stdout);
		usleep(25 * 1000);
	}
}
