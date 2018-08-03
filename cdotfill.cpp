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

	string index[] = {"31", "32", "34", "90","31;1", "32;1", "34;1", "90;1"};

	srand(time(NULL));	
	
	int sizex = size.ws_col;
	
	int rowx = size.ws_row;

	while(true)
	{
		cout << "\033[" << rand()%rowx << ";" << rand()%sizex << "f";
		cout << "\e[" << index[rand()%8] << "m" << "          "  << " . " << "\e[0m";		
		fflush(stdout);
		usleep(10 * 1000);
	}
}
