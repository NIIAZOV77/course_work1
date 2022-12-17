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
	string a, b, c, x;
	cin >> a;
	cin >> b;
	cin >> c;
	x = a + ' ' + b + ' ' + c;
	cout << x << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	x = a + ' ' + b + ' ' + c;
	cout << x;

}