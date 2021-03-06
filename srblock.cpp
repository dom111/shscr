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
	
	string index_colors[] = {"93", "91", "92", "94", "95"};
	
	string index[] = {"▖", "▗", "▘"};
	
	srand(time(NULL));

	while(true)
	{
		for(int i = 0; i < size.ws_col-1; i++)
		{
			cout << "\e[" << index_colors[rand()%5] << "m" << index[rand()%3];
		}
	
		cout << "\n";
		fflush(stdout);
		usleep(50 * 1000);
	}
}
