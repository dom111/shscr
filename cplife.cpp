#include <iostream>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
	system("clear");

	system("setterm -cursor off");

	string index[] = {"\033[1A", "\033[1B", "\033[1C", "\033[1D", "\033[1C", "\033[1D"};
	
	string c[] {"┃", "┏", "┓", "┛", "━", "┓", "┗", "┃", "┛", "┗", "┏", "━"};

	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);

	srand(time(NULL));

	cout << "\033[" << rand()%size.ws_row << ";" << rand()%size.ws_col << "f";
	
	while(true)
	{
		cout << index[rand()%6];
		cout << "\e[38;5;" << to_string(rand()%256) << "m";
		cout << c[rand()%12];
		cout << "\e[0m";
		cout << "\033[1D";
		fflush(stdout);
		usleep(10 * 1000);
	}
}
