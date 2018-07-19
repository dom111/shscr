#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>


using namespace std;

int main()
{
	system("clear");
	srand(time(NULL));

	while(true)
	{
		cout << "\e[92m" << rand()%2;
		fflush(stdout);
		usleep(50 * 1000);
	}
}
