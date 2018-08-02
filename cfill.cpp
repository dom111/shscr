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
	int check = 0;
	string index_colors[] = {"91", "33", "93", "92", "94", "35", "95"};
	string c;
	string block = "█";
	string argv_str = argv[1];
	if(argv_str == "blue")
	{
		c = "34";
	}
	else if(argv_str == "red")
	{
		c = "31";
	}
	else if(argv_str == "green")
	{
		c = "32";
	}
	else if(argv_str == "yellow")
	{
		c = "33";
	}	
	else if(argv_str == "magenta" || argv_str == "purple")
	{
		c = "35";
	}
	else if(argv_str == "cyan")
	{
		c = "36";
	}
	else if(argv_str == "clear")
	{
		c = "49";
		block = " ";
	}
	else if(argv_str == "r")
	{
		check = 1;
	}
	
	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
	
	system("setterm -cursor off");

	srand(time(NULL));	
	
	int sizex = size.ws_col;
	
	int rowx = size.ws_row;

	while(true)
	{
		if(check == 1)
		{
			c = index_colors[rand()%7];
		}
		cout << "\033[" << rand()%rowx << ";" << rand()%sizex << "f";
		cout << "\e[" << c << "m" << block << "\e[0m";		
		fflush(stdout);
		usleep(50 * 1000);
	}
}
