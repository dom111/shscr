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
		ico = "|";
	}
	else
	{
		ico = argv[1];
	}

	system("clear");

	system("setterm -cursor off");

	string index[] = {"\033[1A", "\033[1B", "\033[1C", "\033[1D", "\033[1C", "\033[1D"};
	
	string c[] {"┃", "┏", "┓", "┛", "━", "┓", "┗", "┃", "┛", "┗", "┏", "━"};

	srand(time(NULL));

	while(true)
	{
		cout << index[rand()%6];
		cout << c[rand()%12];
		cout << "\033[1D";
		fflush(stdout);
		usleep(10 * 1000);
	}
}
