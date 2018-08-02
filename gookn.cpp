#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <time.h>

using namespace std;

int main()
{
	system("clear");
	string index[] = {"q", "w", "e", "r", "t", "y" "u", "i", "o", "p", "a", "s", "d", "f", "g", "h", "j", "k", "l", "z", "x", "c", "v", "b", "n", "m", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", " ", "\n"};
	srand(time(NULL));
	

	while(true)
	{
		
		cout << index[rand()%37];
		fflush(stdout);
		usleep(50 * 1000);
		
	}
}
