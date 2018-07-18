#include <iostream>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main()
{
	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
	
	string index_colors[] = {"30;40", "97;107"};
	
	while(true)
	{
		
		for(int x = 0; x < size.ws_row; x++)
		{	
			for(int i = 0; i < size.ws_col-1; i++)
			{
				cout << "\e[" << index_colors[rand()%2] << "m" << "█";
			}
			cout << "\n";
			fflush(stdout);
			usleep(5 * 1000);
		}
	}
}
