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
	while(true)
	{
		cout << "\e[92m" << rand()%2;
		fflush(stdout);
		usleep(3);
	}
}