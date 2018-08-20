#include <iostream>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{	
	system("clear");	
	
	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
	
	system("setterm -cursor off");

	srand(time(NULL));
	
	int sizex = size.ws_col-20;
	
	int rowx = size.ws_row-2;

	while(true)
	{
		cout << "\033[" << rand()%rowx << ";" << rand()%sizex << "f";
		string color = "\e[38;5;" + to_string(1 + (1 * rand ()) %256) + "m";
		for(int i = 0; i < 20/2; i++)
		{
			for(int i = 0; i < 20; i++)
			{
				cout << color << "█" << "\e[0m";
			}
			cout << "\033[1B";
			cout << "\033[" << 20 << "D";
		}
		fflush(stdout);
		usleep(850 * 1000);
		system("clear");
		
	}
}
