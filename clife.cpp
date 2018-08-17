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
	
	if(argc == 1)
	{
		ico = "*";
	}
	else
	{
		ico = argv[1];
	}

	system("clear");

	system("setterm -cursor off");

	string index[] = {"\033[1A", "\033[1B", "\033[1C", "\033[1D", "\033[1C", "\033[1D"};

	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);

	srand(time(NULL));

	cout << "\033[" << rand()%size.ws_row << ";" << rand()%size.ws_col << "f";

	while(true)
	{
		cout << index[rand()%6];
		cout << "\e[38;5;" << to_string(rand()%256) << "m" << ico << "\e[0m";
		cout << "\033[1D";
		fflush(stdout);
		usleep(10 * 1000);
	}
}
