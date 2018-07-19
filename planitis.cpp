#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>

using namespace std;

int main()
{
	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);

	srand(time(NULL));
	
	while(true)
	{
		int col = size.ws_col-1;
		string index[] = {"31", "32", "34", "39","31;1", "32;1", "34;1", "39;1"};
		cout << string(rand()%col, ' ');
		cout << "\e[" << index[rand()%8] << "m" << ".\n" << "\e[0m";
		fflush(stdout);
		usleep(25 * 1000);
	}
}
