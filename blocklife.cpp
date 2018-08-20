#include <iostream>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
	string ico;

	system("clear");

	system("setterm -cursor off");

	string index[] = {"\033[1A", "\033[1B", "\033[1C", "\033[1D", "\033[1C", "\033[1D", "\033[1A", "\033[1A"};

	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
	
	srand(time(NULL));

	cout << "\033[" << rand()%size.ws_row << ";" << rand()%size.ws_col << "f";

	while(true)
	{
		cout << index[rand()%8];
		string color = "\e[38;5;" + to_string(rand()%256) + "m";
		int b_size = 2 + (2 * rand ()) %8;
		for(int i = 0; i < b_size/2; i++)
		{
			for(int i = 0; i < b_size; i++)
			{
				cout << color << "█" << "\e[0m";
			}
			cout << "\033[1B";
			cout << "\033[" << b_size << "D";
		}
		cout << "\033[1A";
		fflush(stdout);
		usleep(10 * 1000);
	}
}
