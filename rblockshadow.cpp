#include <iostream>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int max_size = 20;
	
	if(argc == 2)
	{
		max_size = stoi(argv[1]);
	}
	
	srand(time(NULL));
	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
	
	system("setterm -cursor off");
	
	system("clear");

	srand(time(NULL));	
	
	int sizex = size.ws_col-max_size;
	
	int rowx = size.ws_row-2;

	while(true)
	{
		int y = rand()%rowx;
		int x = rand()%sizex;
		int b_size = rand()%max_size;
		while(true)
		{
			if(b_size % 2 == 0 && (b_size >= 4))
			{
				break;
			}
			else
			{
				b_size = rand()%max_size;
			}
		}
		string color = "\e[38;5;" + to_string(rand()%256) + "m";
		cout << "\033[" << y << ";" << x << "f";
		for(int x = 0; x < b_size/2; x++)
		{
			for(int i = 0; i < b_size-1; i++)
			{
				cout << color << "█" << "\e[0m";
			}
			if (x >= 1)
			{
				cout << color << "░";
			}
			else
			{
				cout << "\033[1C";
			}
			cout << "\033[1B";
			cout << "\033[" << b_size << "D";
		}
		cout << "\033[1C";
		for(int i = 0; i < b_size-1; i++)
		{
			cout << color << "░" << "\e[0m";
		}
		fflush(stdout);
		usleep(10 * 1000);
	}
}
