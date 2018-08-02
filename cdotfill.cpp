#include <iostream>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main()
{
	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
	
	system("setterm -cursor off");
	
	system("clear");

	string index[] = {"96", "91", "92", "94", "95"};

	srand(time(NULL));	
	
	int sizex = size.ws_col;
	
	int rowx = size.ws_row;

	while(true)
	{
		cout << "\033[" << rand()%rowx << ";" << rand()%sizex << "f";
		cout << "\e[" << index[rand()%5] << "m" << "." << "\e[0m";		
		fflush(stdout);
		usleep(10 * 1000);
	}
}
