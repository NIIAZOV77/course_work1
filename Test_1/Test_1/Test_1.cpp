#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string val = "190.93";
	char num = val[1];
	cout << float(num) - '0';
}
