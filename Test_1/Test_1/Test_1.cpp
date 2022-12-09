#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string value1 = "2020:02:25";
	string value2 = "2020:01:31";
	bool a = value1 > value2;
	cout << a;
}
