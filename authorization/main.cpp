#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

struct User
{
	string login;
	string password;
	string role;
};


struct Abonent
{
	string number;     //Номер абонента;
	string surname;     //Фамилия;
	string name;     //Имя;
	string father_name;     //Отчество;
	bool type_of_call;  //Тип вызова (0-входящий, 1-исходящий)
	string number_x;    //Номер исходящего или входящего вызова
	string data_x;           //Дата звонка
	string time_x;       //Время звонка
	float call_dur;      //Продолжительность разговора
	float rate;         //Тариф одной минуты;
};

int num_str(string address, int n);
void making_user_array(User* user_data, int num_str);
int get_role(User *data, int num_str);
void showing(User* data, int num_str);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int user_num_str = num_str("C:\\Users\\umedz\\универ\\программирование\\курсовые\\курсовая_1\\user_data.txt", 3);
	int abonent_num_str = num_str("C:\\Users\\umedz\\универ\\программирование\\курсовые\\курсовая_1\\abonent_data.txt", 8);
	User *user_data = new User[user_num_str];
	Abonent* abonent_data = new Abonent[abonent_num_str];

	making_user_array(user_data, user_num_str);
	int role = get_role(user_data, user_num_str);
	cout << role << endl;
	showing(user_data, user_num_str);
}

int num_str(string address, int n)
{
	ifstream data(address);
	int elements = 0;
	string value0;
	while (!data.eof())
	{
		data >> value0;
		elements++;
	}
	data.close();
	
	int num_str = elements / n;
	return num_str;
}

void making_user_array(User* user_data, int num_str)
{
	
	string value1;
	ifstream data("C:\\Users\\umedz\\универ\\программирование\\курсовые\\курсовая_1\\user_data.txt");
	while (data.good())
	{
		data >> value1;
		for (int i = 0; i < num_str; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				switch (j)
				{
				case 0: user_data[i].login = value1;
				case 1: user_data[i].password = value1;
				case 2: user_data[i].role = value1;
				}

				data >> value1;

			}
		}

	}
	data.close();
}

int get_role(User* data, int num_str)
{
	string log, pass;
	int role;
	cout << "Enter your login: ";
	getline(cin, log);
	cout << "Enter your password: ";
	getline(cin, pass);

	for (int i = 0; i < num_str; i++)
	{

		if (data[i].login == log && data[i].password == pass)
		{
			role = stoi(data[i].role);
			return role;
		}
		else role = -1;
	}

	return role;
}

void showing(User *data, int num_str)
{
	for (int j = 0; j < num_str;j++)
	{
		cout << data[j].login << '\t' << data[j].password << '\t' << data[j].role << '\t';
		cout << endl;
	}
}


