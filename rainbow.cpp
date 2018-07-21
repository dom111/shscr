#include <iostream>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main()
{
	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
	
	string index_colors[] = {"91", "33", "93", "92", "94", "35", "95"};
	

	while(true)
	{
		
		string color = index_colors[rand()%7];		
		
		for(int i = 0; i < size.ws_col-1; i++)
		{
			cout << "\e[" << color << "m" << "█";
		}
	

		cout << "\n";
		fflush(stdout);
		usleep(50 * 1000);
	}
}
