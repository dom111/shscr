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
	
	int sizexx = size.ws_col-15;	

	int rowxx = size.ws_row-15;
	
	string index[] = {"91", "33", "93", "92", "94", "35", "95", "96"};

	string l_seg;

	while(true)
	{
		int counter = 0;

		int sel = rand()%2;
		
		string mov;
		
		cout << "\033[" << rand()%rowxx << ";" << rand() % (sizexx - 15) + 15 << "f";
		string color = to_string(rand()%256);
		if(sel == 0)
		{
			l_seg = "╲";
		}
		else
		{
			l_seg = "╱";
			mov = "\033[1D";
		}
		while(counter <= 15)
		{
			counter++;	
			cout << "\e[38;5;" << color << ";1" << "m";
			cout << l_seg;
			cout << "\e[0m";
			fflush(stdout);
			usleep(50 * 1000);
			cout << "\033[1B";
			cout << mov;
			cout << mov;			
		}
		fflush(stdout);
		usleep(50 * 1000);
	}
}
