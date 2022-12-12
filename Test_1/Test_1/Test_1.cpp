#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <algorithm>


using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int time_ischod = 268;
	string isch;
	time_ischod % 60 > 10 ? isch = to_string(time_ischod / 60) + ':' + to_string(time_ischod % 60) : isch = to_string(time_ischod / 60) + ":0" + to_string(time_ischod % 60);
	cout << isch;
}