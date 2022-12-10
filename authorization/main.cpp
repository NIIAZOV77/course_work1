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
	string type_of_call;   //Тип вызова
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
	void show_abonents(string address) //Отображение абонентов
	{
		fstream f(address);
		string val;
		while (!f.eof())
		{
			for (int i = 0; i < 10; i++)
			{
				f >> val;
				cout << val << '\t';
			}
			cout << endl;
		}
		f.close();
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

	void sort(abonent* data, string address, int num_str, int key) //Сортировка данных
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
			show_abonents(address);
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
			show_abonents(address);
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
			show_abonents(address);
			break;
		}
		}
	}

	/*void indiv_task(abonent* data, int num_str)
	{
		string begin_date;
		string end_date;
		float time_ischod;
		float time_vhod ;
		float sum ;
		cout << "Введите начальную дату в формате гггг:мм:дд: ";
		cin >> begin_date;
		cout << "Введите конечную дату в формате гггг:мм:дд: ";
		cin >> end_date;
		cout << endl;
		string* arr = new string[num_str];
		int j;
		for (int i = 0; i < num_str-1; i++)
		{
			for (j = 0; j < i; j++)
				if (data[i].number == data[j].number) break;
			if (i == j) { arr[i] = data[i].number; }

		}
		for (int i = 0; i < num_str; i++)
		{
			cout << "Вывод по абоненту " << data[i].surname << ' ' << data[i].name << ' ' << data[i].father_name << endl << endl;
			for (int j = 0; j < num_str; j++)
			{
				if (data[j].number == arr[i])
				{
					if (data[j].date_x > begin_date && data[j].date_x < end_date)
					{
						cout << data[i].number << '\t' << data[i].surname << '\t' << data[i].name << '\t' << data[i].father_name << '\t' << data[i].type_of_call << '\t'
							<< data[i].number_x << '\t' << data[i].date_x << '\t' << data[i].time_x << '\t' << data[i].call_dur << '\t' << data[i].rate << endl;
					}
				}
			}
		}

	}*/
};

class Administrator: public User
{
public:
	void show_users(string address) //Отображение пользователей
	{
		fstream f(address);
		string val;
		while (!f.eof())
		{
			for (int i = 0; i < 3; i++)
			{
				f >> val;
				cout << val << '\t';
			}
			cout << endl;
		}
		f.close();
	}

	void add_new_user(string address) //Добавление нового пользователя, так же нужно обновлять переменную количество строк
	{
		fstream f(address, ios::app);
		user Us;
		cout << "Введите логин нового пользователя: ";
		cin >> Us.login;
		cout << "Введите пароль нового пользователя: ";
		cin >> Us.password;
		cout << "Введите роль нового пользователя: ";
		cin >> Us.role;
		f << endl << Us.login << ' ' << Us.password << ' ' << Us.role;
		f.close();
	}

	void add_new_abonent(string address) //Добавление новой записи абонента, так же нужно обновлять переменную количество строк
	{
		fstream f(address, ios::app);
		abonent Ab;
		cout << "Введите номер абонента: ";
		cin >> Ab.number;
		cout << "Введите фамилию абонента: ";
		cin >> Ab.surname;
		cout << "Введите имя абонента: ";
		cin >> Ab.name;
		cout << "Введите отчество абонента: ";
		cin >> Ab.father_name;
		cout << "Введите тип вызова: ";
		cin >> Ab.type_of_call;
		cout << "Введите номер исходящего или входящего звонка: ";
		cin >> Ab.number_x;
		cout << "Введите дату звонка: ";
		cin >> Ab.date_x;
		cout << "Введите время звонка: ";
		cin >> Ab.time_x;
		cout << "Введите продолжительность разговора: ";
		cin >> Ab.call_dur;
		cout << "Введите тариф одной минуты: ";
		cin >> Ab.rate;

		f << endl << Ab.number << ' ' << Ab.surname << ' ' << Ab.name << ' ' << Ab.father_name << ' ' << Ab.type_of_call << ' '
			<< Ab.number_x << ' ' << Ab.date_x << ' ' << Ab.time_x << ' ' << Ab.call_dur << ' ' << Ab.rate;
		f.close();
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string user_address = "C:\\Users\\umedz\\универ\\программирование\\курсовые\\курсовая_1\\user_data.txt";
	string abonent_address = "C:\\Users\\umedz\\универ\\программирование\\курсовые\\курсовая_1\\abonent_data.txt";
	int user_num_str = num_str(user_address, 3);
	int abonent_num_str = num_str(abonent_address, 8);
	user *user_data = new user[user_num_str];
	abonent* abonent_data = new abonent[abonent_num_str];
	
	making_user_array(user_data, user_num_str);
	making_abonent_array(abonent_data, abonent_num_str);
	int role = get_role(user_data, user_num_str);
	

	Administrator add;
	
}

int num_str(string address, int n)
{
	ifstream data(address);
	int elements = 0;
	string value0;
	data >> value0;
	elements++;
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
	while (!data.eof())
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
	while (!data.eof())
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
