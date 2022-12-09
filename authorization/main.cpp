#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

struct user
{
	string login;
	string password;
	string role;
};


struct abonent
{
	string number;         //Номер абонента;
	string surname;        //Фамилия;
	string name;           //Имя;
	string father_name;    //Отчество;
	string type_of_call;   //Тип вызова (0-входящий, 1-исходящий)
	string number_x;       //Номер исходящего или входящего вызова
	string date_x;         //Дата звонка
	string time_x;         //Время звонка
	string call_dur;       //Продолжительность разговора
	string rate;           //Тариф одной минуты;
};

int num_str(string address, int n);
void making_user_array(user* user_data, int num_str);
int get_role(user *data, int num_str);
void making_abonent_array(abonent* abonent_data, int num_str);

class User
{
public:
	void show_abonents(abonent* data, int num_str) //Отображение пользователей
	{
		string value;
		for (int i = 0; i < num_str; i++)
		{
			cout << data[i].number << '\t' << data[i].surname << '\t' << data[i].name << '\t' << data[i].father_name << '\t' << data[i].type_of_call << '\t'
				<< data[i].number_x << '\t' << data[i].date_x << '\t' << data[i].time_x << '\t' << data[i].call_dur << '\t' << data[i].rate << endl;
		}
		cout << endl;
	}

	void finding(abonent* data, int num_str, int key)//Поиск 
	{
		switch (key)
		{
		case 1: //Поиск по фамилии
		{
			string surname;
			cout << "Введите фамилию: ";
			cin >> surname;
			for (int i = 0; i < num_str; i++)
			{
				if (data[i].surname == surname)
				{
					cout << data[i].number << '\t' << data[i].surname << '\t' << data[i].name << '\t' << data[i].father_name << '\t' << data[i].type_of_call << '\t'
						<< data[i].number_x << '\t' << data[i].date_x << '\t' << data[i].time_x << '\t' << data[i].call_dur << '\t' << data[i].rate << endl;
				}
			}
			break;
		}
		case 2: //Поиск имя
		{
			string name;
			cout << "Введите имя: ";
			cin >> name;
			for (int i = 0; i < num_str; i++)
			{
				if (data[i].name == name)
				{
					cout << data[i].number << '\t' << data[i].surname << '\t' << data[i].name << '\t' << data[i].father_name << '\t' << data[i].type_of_call << '\t'
						<< data[i].number_x << '\t' << data[i].date_x << '\t' << data[i].time_x << '\t' << data[i].call_dur << '\t' << data[i].rate << endl;
				}			
			}
			break;
		}
		case 3: //Поиск по отчеству
		{
			string father_name;
			cout << "Введите отчество: ";
			cin >> father_name;
			for (int i = 0; i < num_str; i++)
			{
				if (data[i].father_name == father_name)
				{
					cout << data[i].number << '\t' << data[i].surname << '\t' << data[i].name << '\t' << data[i].father_name << '\t' << data[i].type_of_call << '\t'
						<< data[i].number_x << '\t' << data[i].date_x << '\t' << data[i].time_x << '\t' << data[i].call_dur << '\t' << data[i].rate << endl;
				}
			}
			break;
		}
		case 4: //Поиск по дате
		{
			string date;
			cout << "Введите дату: ";
			cin >> date;
			for (int i = 0; i < num_str; i++)
			{
				if (data[i].date_x == date)
				{
					cout << data[i].number << '\t' << data[i].surname << '\t' << data[i].name << '\t' << data[i].father_name << '\t' << data[i].type_of_call << '\t'
						<< data[i].number_x << '\t' << data[i].date_x << '\t' << data[i].time_x << '\t' << data[i].call_dur << '\t' << data[i].rate << endl;
				}
			}
			break;
		}
		case 5: //Поиск по номеру телефона
		{
			string number;
			cout << "Введите номер телефона: ";
			cin >> number;
			for (int i = 0; i < num_str; i++)
			{
				if (data[i].surname == number)
				{
					cout << data[i].number << '\t' << data[i].surname << '\t' << data[i].name << '\t' << data[i].father_name << '\t' << data[i].type_of_call << '\t'
						<< data[i].number_x << '\t' << data[i].date_x << '\t' << data[i].time_x << '\t' << data[i].call_dur << '\t' << data[i].rate << endl;
				}
			}
			break;
		}
		}
	}

	void sort(abonent* data, int num_str, int key) //Сортировка данных
	{
		abonent *data1 = new abonent[num_str];
		data1 = data;
		abonent temp;
		switch (key)
		{
		case 1: //Сортировка по имени
		{
			for (int i = 0; i < num_str - 1; i++)
			{
				for (int j = 0; j < num_str - 1; j++)
				{
					if (data1[j].name > data1[j + 1].name)
					{
						temp = data[j];
						data[j] = data[j + 1];
						data[j + 1] = temp;
					}
				}
			}
			show_abonents(data1, num_str);
			break;
		}
		
		case 2: //Сортировка по фамилии
		{
			for (int i = 0; i < num_str - 1; i++)
			{
				for (int j = 0; j < num_str - 1; j++)
				{
					if (data1[j].surname > data1[j + 1].surname)
					{
						temp = data[j];
						data[j] = data[j + 1];
						data[j + 1] = temp;
					}
				}
			}
			show_abonents(data1, num_str);
			break;
		}
		case 3: //Сортировка по дате
		{
			for (int i = 0; i < num_str - 1; i++)
			{
				for (int j = 0; j < num_str - 1; j++)
				{
					if (data1[j].date_x > data1[j + 1].date_x)
					{
						temp = data[j];
						data[j] = data[j + 1];
						data[j + 1] = temp;
					}
				}
			}
			show_abonents(data1, num_str);
			break;
		}
		}
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int user_num_str = num_str("C:\\Users\\umedz\\универ\\программирование\\курсовые\\курсовая_1\\user_data.txt", 3);
	int abonent_num_str = num_str("C:\\Users\\umedz\\универ\\программирование\\курсовые\\курсовая_1\\abonent_data.txt", 8);
	user *user_data = new user[user_num_str];
	abonent* abonent_data = new abonent[abonent_num_str];

	making_user_array(user_data, user_num_str);
	making_abonent_array(abonent_data, abonent_num_str);
	int role = get_role(user_data, user_num_str);

	
	
	User add;
	//add.show_abonents(abonent_data, abonent_num_str);
	//add.finding(abonent_data, abonent_num_str, 3);
	//add.sort(abonent_data, abonent_num_str, 3);
}

int num_str(string address, int n)
{
	ifstream data(address);
	int elements = 0;
	string value0;
	data >> value0;
	while (!data.eof())
	{
		elements++;
		data >> value0;
	}
	data.close();
	
	int num_str = elements / n;
	return num_str;
}

void making_user_array(user* user_data, int num_str)
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

void making_abonent_array(abonent* abonent_data, int num_str)
{
	string value;
	ifstream data("C:\\Users\\umedz\\универ\\программирование\\курсовые\\курсовая_1\\abonent_data.txt");
	while (data.good())
	{
		data >> value;
		for (int i = 0; i < num_str; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				switch (j)
				{
				case 0: { abonent_data[i].number = value; break; }
				case 1: {abonent_data[i].surname = value; break; }
				case 2: {abonent_data[i].name = value; break; }
				case 3: {abonent_data[i].father_name = value; break; }
				case 4: {abonent_data[i].type_of_call = value; break; }
				case 5: {abonent_data[i].number_x = value; break; }
				case 6: {abonent_data[i].date_x = value; break; }
				case 7: {abonent_data[i].time_x = value; break; }
				case 8: {abonent_data[i].call_dur = value; break; }
				case 9: {abonent_data[i].rate = value; break; }
				}

				data >> value;

			}
		}

	}
	data.close();
}

int get_role(user* data, int num_str)
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


