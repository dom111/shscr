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

	cout << "\033[2J";

	srand(time(NULL));	
	
	int sizex = size.ws_col-10;
	
	int rowx = size.ws_row-10;
	
	string index[] = {"91", "33", "93", "92", "94", "35", "95", "96"};

	while(true)
	{
		int counter = 0;
		
		cout << "\033[" << rand()%rowx << ";" << rand()%sizex << "f";
		string color = index[rand()%8];
		while(counter <= 10)
		{
			counter++;	
			cout << "\e[" << color << ";1" << "m";
			cout << "╲";
			cout << "\e[0m";
			cout << "\033[1B";
		}
		fflush(stdout);
		usleep(50 * 1000);
	}
}