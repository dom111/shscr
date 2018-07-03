#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <term.h>


using namespace std;

int main(int argc, char *argv[])
{
	
	system("clear");
	string c;
	string argv_str = argv[1];
	if(argv_str == "blue")
	{
		c = "4";
	}
	else if(argv_str == "red")
	{
		c = "1";
	}
	else if(argv_str == "green")
	{
		c = "2";
	}
	else if(argv_str == "yellow")
	{
		c = "3";
	}	
	else if(argv_str == "magenta" || argv_str == "purple")
	{
		c = "5";
	}
	else if(argv_str == "cyan")
	{
		c = "6";
	}
	while(true)
	{
		cout << "\e[3" << c << ";4" << c << "m0";
		fflush(stdout);
		usleep(500 * 1000);
	}
}
