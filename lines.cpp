#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <term.h>


using namespace std;

int main()
{
	
	string index[] = {"null", "91;4", "92;4", "93;4", "94;4", "95;4", "96;4"};
	
	while(true)
	{
		cout << "\e[30m";
		cout << "\e[" << index[rand() % 6] << "m";
		cout << "\n";
	}
}
