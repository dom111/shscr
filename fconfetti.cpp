#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>

using namespace std;

int main()
{
	system("clear");
	string index[] = {"`", "~", "!" , "@", "#", "$", "%", "^", "&", "*", "(", ")", "-", "_", "=", "+", "[", "{", "]", "}", "\\", "|", ";", ":", "'", "\"", ",", "<", ".", ">", "/", "?"};
	string index_colors[] = {"93", "91", "92", "94", "95"};
	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
	
	srand(time(NULL));

	while(true)
	{
		for(int i = 0; i < size.ws_col-1; i++)
		{
			cout << "\e[" << index_colors[rand()%5] << "m" << index[rand()%32] << " ";
		}
	
		cout << "\n";
		fflush(stdout);
		usleep(50 * 1000);
	}
}
