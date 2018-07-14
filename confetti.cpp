#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>

using namespace std;

int main()
{
	system("clear");
	string index[] = {"`", "~", "!" , "@", "#", "$", "%", "^", "&", "*", "(", ")", "-", "_", "=", "+", "[", "{", "]", "}", "\\", "|", ";", ":", "'", "\"", ",", "<", ".", ">", "/", "?"};
	string index_colors[] = {"93", "91", "92", "94", "95"};
	
	while(true)
	{
		
		cout << "\e[" << index_colors[rand()%5] << "m" << index[rand()%32] << " ";
		fflush(stdout);
		usleep(50 * 1000);
		
	}
}
