#include <iostream>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
	int check = 1;
	
	int check2 = 0;

	string index[] = {"91", "33", "93", "92", "94", "35", "95"};	

	system("clear");	
	
	string ui;
	
	string a1 = argv[1];
	
	if(a1 == "color")
	{
		check = 2;
		check2 = 1;
	}

	for(int i = check; i < argc; i++)
	{
		ui = ui + argv[i] + " ";
	}
	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
	
	system("setterm -cursor off");

	srand(time(NULL));	
	
	int sizex = size.ws_col;
	
	int rowx = size.ws_row;

	while(true)
	{
		cout << "\033[" << rand()%rowx << ";" << rand()%sizex << "f";
		if(check2 == 1)
		{
			cout << "\e[38;5;" << to_string(rand()%256) << "m" << ui << "\e[0m";
			fflush(stdout);
  			usleep(50 * 1000);
		}
		else
		{
			cout << ui;	
			fflush(stdout);
			usleep(50 * 1000);
		}
	}
}
