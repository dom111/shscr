#include <iostream>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
	srand(time(NULL));
	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
	
	system("setterm -cursor off");

	srand(time(NULL));	
	
	int sizex = size.ws_col;
	
	int rowx = size.ws_row;

	while(true)
	{
		string c = to_string(rand()%256);
		cout << "\033[" << rand()%rowx << ";" << rand()%sizex << "f";
		cout << "\e[38;5;" << c << "m" << "█" << "\e[0m";		
		fflush(stdout);
		usleep(500);
	}
}
