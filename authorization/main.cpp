#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdio.h>

using namespace std;

struct user
{
	string login; //логин
	string password; //пароль
	string role; //роль
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
	void show_abonents(string address) //Отображение записей разговоров
	{
		fstream f(address);
		string val;
		cout << endl;
		while (!f.eof())
		{
			for (int i = 0; i < 10; i++)
			{
				f >> val;
				cout << val << "\t";
			}
			cout << endl;
		}
		cout << endl;
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
				cout << endl;
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
				cout << endl;
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
				cout << endl;
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
				cout << endl;
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
				if (data[i].number == number)
				{
					cout << data[i].number << '\t' << data[i].surname << '\t' << data[i].name << '\t' << data[i].father_name << '\t' << data[i].type_of_call << '\t'
						<< data[i].number_x << '\t' << data[i].date_x << '\t' << data[i].time_x << '\t' << data[i].call_dur << '\t' << data[i].rate << endl;
				}
				cout << endl;
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
			for (int i = 0; i < num_str-1; i++)
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
			for (int i = 0; i < num_str; i++)
			{
				cout << data[i].number << '\t' << data[i].surname << '\t' << data[i].name << '\t' << data[i].father_name << '\t' << data[i].type_of_call << '\t'
					<< data[i].number_x << '\t' << data[i].date_x << '\t' << data[i].time_x << '\t' << data[i].call_dur << '\t' << data[i].rate << endl;
			}
			cout << endl;
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
			for (int i = 0; i < num_str; i++)
			{
				cout << data[i].number << '\t' << data[i].surname << '\t' << data[i].name << '\t' << data[i].father_name << '\t' << data[i].type_of_call << '\t'
					<< data[i].number_x << '\t' << data[i].date_x << '\t' << data[i].time_x << '\t' << data[i].call_dur << '\t' << data[i].rate << endl;
			}
			cout << endl;
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
			for (int i = 0; i < num_str; i++)
			{
				cout << data[i].number << '\t' << data[i].surname << '\t' << data[i].name << '\t' << data[i].father_name << '\t' << data[i].type_of_call << '\t'
					<< data[i].number_x << '\t' << data[i].date_x << '\t' << data[i].time_x << '\t' << data[i].call_dur << '\t' << data[i].rate << endl;
			}
			cout << endl;
			break;
		}
		}
	}

	void indiv_task(abonent* data, int num_str)//Поиск во временном отрезке
	{
		string begin_date;
		string end_date;
		int time_ischod;
		int time_vhod;
		int sum;
		cout << "Введите начальную дату в формате гггг:мм:дд: ";
		cin >> begin_date;
		cout << "Введите конечную дату в формате гггг:мм:дд: ";
		cin >> end_date;
		cout << endl;
		bool not_u = false;
		int count = 0;
		string* uniq_arr = new string[num_str];
		for (int i = 0; i < num_str; i++)
		{
			bool not_u = false;
			for (int j = 0; j < i; j++)
			{
				if (uniq_arr[j] == data[i].number)
				{
					not_u = true;
					break;
				}
			}
			if (not_u == true)
				continue;
			uniq_arr[i] = data[i].number;
			count++;	
		}

		for (int i = 0; i < count; i++)
		{
			time_ischod = 0;
			sum = 0;
			time_vhod = 0;
			cout << "Вывод по абоненту: " << uniq_arr[i] << endl;
			for (int j = 0; j < num_str; j++)
			{
				if (data[j].number == uniq_arr[i] && data[j].date_x > begin_date && data[j].date_x < end_date)
				{
					cout << data[j].number << '\t' << data[j].surname << '\t' << data[j].name << '\t' << data[j].father_name << '\t' << data[j].type_of_call
						<< '\t' << data[j].number_x << '\t' << data[j].date_x << '\t' << data[j].time_x << '\t' << data[j].call_dur << '\t' << data[j].rate << endl;
					string str1 = data[j].call_dur;
					replace(str1.begin(), str1.end(), ':', '.');
					int min = stoi(str1);
					float sec = stof(str1) - stoi(str1);
					int total_sec = round((min * 60 + sec * 100) * 10) / 10;
					int cost = stoi(string(1, data[j].rate[0])) * min;
					if (data[j].type_of_call == "исходящий")
						time_ischod += total_sec;
					if (data[j].type_of_call == "входящий")
						time_vhod += total_sec;
					sum += cost;
				}
			}
			string isch, vh;
			time_ischod % 60 > 10 ? isch = to_string(time_ischod / 60) + ':' + to_string(time_ischod % 60) : isch = to_string(time_ischod / 60) + ":0" + to_string(time_ischod % 60);
			time_vhod % 60 > 10 ? vh = to_string(time_vhod / 60) + ':' + to_string(time_vhod % 60) : vh = to_string(time_vhod / 60) + ":0" + to_string(time_vhod % 60);
			cout << "Общее время исходящих звонков: " << isch << endl << "Общее время входящих звонков: " << vh << endl << "Общая сумма потраченная на исходящие звонки: " << sum << endl;
			cout << endl;
		}
		
	}
};

class Administrator: public User
{
public:
	void show_users(string address) //Отображение пользователей
	{
		fstream f(address);
		string val;
		cout << endl;
		while (!f.eof())
		{
			for (int i = 0; i < 3; i++)
			{
				f >> val;
				cout << val << '\t';
			}
			cout << endl;
		}
		cout << endl;
		f.close();
	}

	void add_new_user(string address, int num_str) //Добавление нового пользователя
	{
		ifstream f(address);
		user Us;
		user ser;
		string* arr = new string[num_str];
		int i = 0;
		while (!f.eof())
		{
			f >> ser.login >> ser.password >> ser.role;
			arr[i] = ser.login;
			i++;
		}
		f.close();
		fstream f1(address, ios::app);
		bool isa;
		while (true)
		{
			isa = false;
			cout << "Введите логин нового пользователя: ";
			cin >> Us.login;
			cout << "Введите пароль нового пользователя: ";
			cin >> Us.password;
			cout << "Введите роль нового пользователя: ";
			cin >> Us.role;
			for (int i = 0; i < num_str; i++)
			{
				if (Us.login == arr[i])
				{
					cout << "Пользователь с таким логином уже есть, введите еще раз\n";
					isa = true;
					continue;
				}
			}
			if (isa != true)
			{
				f1 << endl << Us.login << ' ' << Us.password << ' ' << Us.role;
				break;
			}
		}
		cout << endl;
		f1.close();
	}

	void add_new_abonent(string address) //Добавление новой записи разговора, так же нужно обновлять переменную количество строк и массив
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
		cout << endl;
		f << endl << Ab.number << ' ' << Ab.surname << ' ' << Ab.name << ' ' << Ab.father_name << ' ' << Ab.type_of_call << ' '
			<< Ab.number_x << ' ' << Ab.date_x << ' ' << Ab.time_x << ' ' << Ab.call_dur << ' ' << Ab.rate;
		f.close();
	}

	void remove_user(string address, int num_str) //Функция для удаления пользователя
	{
		ifstream f(address);
		ofstream t("C:\\Users\\umedz\\универ\\программирование\\курсовые\\курсовая_1\\text.txt", ios::trunc);
		cout << "Введите данные для удаления\n";
		cout << "Введите логин, пароль и роль по очереди\n";
		string a, b, c, values;
		cin >> a;
		cin >> b;
		cin >> c;
		values = a + ' ' + b + ' ' + c;
		string f_values;
		int count = 0;
		while (!f.eof())
		{
			getline(f, f_values);
			if (values == f_values)
				continue;
			t << f_values;
			if (count < num_str-2)
				t << '\n';
			count++;
		}
		t.close();
		f.close();
		ifstream t1("C:\\Users\\umedz\\универ\\программирование\\курсовые\\курсовая_1\\text.txt");
		ofstream f1(address, ios::trunc);
		string t_values;
		count = 0;
		while (!t1.eof())
		{
			getline(t1, t_values);
			f1 << t_values;
			if (count < num_str-2)
				f1 << '\n';
			count++;
		}
		cout << endl;
		t1.close();
		f1.close();
	}

	void remove_abonent(string address, int num_str) //Функция для удаления записи разговара, нужно обновлять данные о количестве строк и массив
	{
		ifstream f(address);
		ofstream t("C:\\Users\\umedz\\универ\\программирование\\курсовые\\курсовая_1\\text.txt", ios::trunc);
		cout << "Введите данные для удаления\n";
		cout << "Введите все данные разговора по очереди\n";
		string values, a1, a2, a3, a4, a5, a6, a7, a8,a9,a10;
		cout << "Введите номер абонента: ";
		cin >> a1;
		cout << "Введите фамилию абонента: ";
		cin >> a2;
		cout << "Введите имя абонента: ";
		cin >> a3;
		cout << "Введите отчество абонента: ";
		cin >> a4;
		cout << "Введите тип вызова: ";
		cin >> a5;
		cout << "Введите номер исходящего или входящего звонка: ";
		cin >> a6;
		cout << "Введите дату звонка: ";
		cin >> a7;
		cout << "Введите время звонка: ";
		cin >> a8;
		cout << "Введите продолжительность разговора: ";
		cin >> a9;
		cout << "Введите тариф одной минуты: ";
		cin >> a10;
		values = a1 + ' ' + a2 + ' ' + a3 + ' ' + a4 + ' ' + a5 + ' ' + a6 + ' ' + a7 + ' ' + a8 + ' ' + a9 + ' ' + a10;
		
		string f_values;
		int count = 0;
		while (!f.eof())
		{
			getline(f, f_values);
			if (values == f_values)
				continue;
			t << f_values;
			if (count < num_str - 2)
				t << '\n';
			count++;
		}
		t.close();
		f.close();
		ifstream t1("C:\\Users\\umedz\\универ\\программирование\\курсовые\\курсовая_1\\text.txt");
		ofstream f1(address, ios::trunc);
		string t_values;
		count = 0;
		while (!t1.eof())
		{
			getline(t1, t_values);
			f1 << t_values;
			if (count < num_str - 2)
				f1 << '\n';
			count++;
		}
		cout << endl;
		t1.close();
		f1.close();
	}

	void edit_user(string address, int num_str) //Функция для изменения пользователя, нужно обновлять данные о количестве строк и массив
	{
		ifstream f(address);
		ofstream t("C:\\Users\\umedz\\универ\\программирование\\курсовые\\курсовая_1\\text.txt", ios::trunc);
		string values, new_values, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
		cout << "Введите данные которые вы хотите изменить\n";
		cout << "Введите логин, пароль и роль по очереди\n";
		cin >> a1;
		cin >> a2;
		cin >> a3;
		values = a1 + ' ' + a2 + ' ' + a3;
		cout << "Введите измененные данные\n";
		cout << "Введите логин, пароль и роль по очереди\n";
		cin >> a1;
		cin >> a2;
		cin >> a3;
		new_values = a1 + ' ' + a2 + ' ' + a3;
		string f_values;
		int count = 0;
		while (!f.eof())
		{
			getline(f, f_values);
			if (values == f_values)
			{
				f_values = new_values;
			}
			t << f_values;
			if (count < num_str - 1)
				t << '\n';
			count++;
		}
		t.close();
		f.close();
		ifstream t1("C:\\Users\\umedz\\универ\\программирование\\курсовые\\курсовая_1\\text.txt");
		ofstream f1(address, ios::trunc);
		string t_values;
		count = 0;
		while (!t1.eof())
		{
			getline(t1, t_values);
			f1 << t_values;
			if (count < num_str - 1)
				f1 << '\n';
			count++;
		}
		cout << endl;
		t1.close();
		f1.close();
	}

	void edit_abonent(string address, int num_str) //Функция для изменения записи звонка, нужно обновлять данные о количестве строк и массив
	{
		ifstream f(address);
		ofstream t("C:\\Users\\umedz\\универ\\программирование\\курсовые\\курсовая_1\\text.txt", ios::trunc);
		string values, new_values, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
		cout << "Введите данные которые вы хотите изменить\n";
		cout << "Введите все данные разговора по очереди\n";
		cout << "Введите номер абонента: ";
		cin >> a1;
		cout << "Введите фамилию абонента: ";
		cin >> a2;
		cout << "Введите имя абонента: ";
		cin >> a3;
		cout << "Введите отчество абонента: ";
		cin >> a4;
		cout << "Введите тип вызова: ";
		cin >> a5;
		cout << "Введите номер исходящего или входящего звонка: ";
		cin >> a6;
		cout << "Введите дату звонка: ";
		cin >> a7;
		cout << "Введите время звонка: ";
		cin >> a8;
		cout << "Введите продолжительность разговора: ";
		cin >> a9;
		cout << "Введите тариф одной минуты: ";
		cin >> a10;
		values = a1 + ' ' + a2 + ' ' + a3 + ' ' + a4 + ' ' + a5 + ' ' + a6 + ' ' + a7 + ' ' + a8 + ' ' + a9 + ' ' + a10;
		cout << "Введите измененные данные\n";
		cout << "Введите все данные разговора по очереди\n";
		cin >> a1;
		cout << "Введите фамилию абонента: ";
		cin >> a2;
		cout << "Введите имя абонента: ";
		cin >> a3;
		cout << "Введите отчество абонента: ";
		cin >> a4;
		cout << "Введите тип вызова: ";
		cin >> a5;
		cout << "Введите номер исходящего или входящего звонка: ";
		cin >> a6;
		cout << "Введите дату звонка: ";
		cin >> a7;
		cout << "Введите время звонка: ";
		cin >> a8;
		cout << "Введите продолжительность разговора: ";
		cin >> a9;
		cout << "Введите тариф одной минуты: ";
		cin >> a10;
		new_values = a1 + ' ' + a2 + ' ' + a3 + ' ' + a4 + ' ' + a5 + ' ' + a6 + ' ' + a7 + ' ' + a8 + ' ' + a9 + ' ' + a10;
		string f_values;
		int count = 0;
		while (!f.eof())
		{
			getline(f, f_values);
			if (values == f_values)
			{
				f_values = new_values;
			}
			t << f_values;
			if (count < num_str - 1)
				t << '\n';
			count++;
		}
		t.close();
		f.close();
		ifstream t1("C:\\Users\\umedz\\универ\\программирование\\курсовые\\курсовая_1\\text.txt");
		ofstream f1(address, ios::trunc);
		string t_values;
		count = 0;
		while (!t1.eof())
		{
			getline(t1, t_values);
			f1 << t_values;
			if (count < num_str - 1)
				f1 << '\n';
			count++;
		}
		cout << endl;
		t1.close();
		f1.close();
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string user_address = "C:\\Users\\umedz\\универ\\программирование\\курсовые\\курсовая_1\\user_data.txt";
	string abonent_address = "C:\\Users\\umedz\\универ\\программирование\\курсовые\\курсовая_1\\abonent_data.txt";
	int user_num_str = num_str(user_address, 3);
	int abonent_num_str = num_str(abonent_address, 10);
	if (user_num_str == 1)
	{
		cout << "Первый запуск программы, добавьте новую учетную запись\n";
		Administrator add;
		add.add_new_user(user_address, 1);
		user_num_str++;
	}
	user* user_data = new user[user_num_str];
	abonent* abonent_data = new abonent[abonent_num_str];
	
	making_user_array(user_data, user_num_str);
	making_abonent_array(abonent_data, abonent_num_str);
	
	int role = get_role(user_data, user_num_str);
	
	
	int N, M, X, Y;
	while (role == 1)
	{
		Administrator ad;
		cout << "______________________________________________________" << endl;
		cout << "                   Меню администратора                " << endl;
		cout << "______________________________________________________" << endl << endl;
		cout << "1.	Управление учетными записями пользователей" << endl;
		cout << "2.	Работа с данными" << endl;
		cout << "3.	Выход из программы" << endl << endl;
		cout << "Выберете пункт меню" << endl;
		cin >> N;
		cout << endl;
		switch (N)
		{
		case 1:
		{
			M = 0;
			while (M != 5)
			{
				cout << "______________________________________________________" << endl;
				cout << "  Управление учетными записями пользователей         " << endl;
				cout << "______________________________________________________" << endl << endl;
				cout << "1.	Просмотр всех учетных записей" << endl;
				cout << "2.	Добавление новой учетной записи" << endl;
				cout << "3.	Редактирование учетной записи" << endl;
				cout << "4.	Удаление учетной записи" << endl;
				cout << "5.	Возврат в меню администратора" << endl << endl;
				cout << "Выберете пункт меню" << endl;
				cin >> M;
				cout << endl;

				switch (M)
				{
				case 1:
				{
					cout << "Учетные записи" << endl;
					ad.show_users(user_address);
					break;
				}
				case 2:
				{
					cout << "Добавление новой учетной записи" << endl;
					ad.add_new_user(user_address, user_num_str);
					user_num_str = num_str(user_address, 3);
					break;
				}
				case 3:
				{
					cout << "Редактирование учетной записи" << endl;
					ad.edit_user(user_address, user_num_str);
					user_num_str = num_str(user_address, 3);
					break;
				}
				case 4: 
				{
					cout << "Удаление учетной записи" << endl;
					ad.remove_user(user_address, user_num_str);
					user_num_str = num_str(user_address, 3);
					break;
				}
				case 5: break;
				}
			}
			continue;
		}

		case 2:
		{
			M = 0;
			while (M != 3)
			{
				cout << "______________________________________________________" << endl;
				cout << "                    Работа с данными         " << endl;
				cout << "______________________________________________________" << endl << endl;
				cout << "1.	Редактирование" << endl;
				cout << "2.	Обработка" << endl;
				cout << "3.	Возврат в меню администратора" << endl << endl;
				cout << "Выберете пункт меню" << endl;
				cin >> M;
				cout << endl;
				switch (M)
				{
				case 1:
				{
					X = 0;
					while (X != 5)
					{
						cout << "______________________________________________________" << endl;
						cout << "                    Редактирование         " << endl;
						cout << "______________________________________________________" << endl << endl;
						cout << "1.	Просмотр всех записей" << endl;
						cout << "2.	Добавление новой записи" << endl;
						cout << "3.	Редактирование записи" << endl;
						cout << "4.	Удаление записи" << endl;
						cout << "5.	Возврат в меню работы с данными" << endl << endl;
						cout << "Выберете пункт меню" << endl;
						cin >> X;
						switch (X)
						{
						case 1:
						{
							cout << "Просмотр всех данных" << endl;
							ad.show_abonents(abonent_address);
							break;
						}
						case 2:
						{
							cout << "Добавление новой записи" << endl;
							ad.add_new_abonent(abonent_address);
							abonent_num_str++;
							delete[] abonent_data;
							abonent* abonent_data = new abonent[abonent_num_str];
							making_abonent_array(abonent_data, abonent_num_str);
							break;

						}
						case 3:
						{
							cout << "Редактирование записи" << endl;
							ad.edit_abonent(abonent_address, abonent_num_str);
							delete[] abonent_data;
							abonent* abonent_data = new abonent[abonent_num_str];
							making_abonent_array(abonent_data, abonent_num_str);
							break;

						}
						case 4:
						{
							cout << "Удаление записи" << endl;
							ad.remove_abonent(abonent_address, abonent_num_str);
							abonent_num_str -= 1;
							delete[] abonent_data;
							abonent* abonent_data = new abonent[abonent_num_str];
							making_abonent_array(abonent_data, abonent_num_str);
							break;

						}
						case 5:break;
						}
					}
					continue;
				}
				case 2:
				{
					X = 0;
					while (X != 4)
					{
						cout << "______________________________________________________" << endl;
						cout << "                    Обработка         " << endl;
						cout << "______________________________________________________" << endl << endl;
						cout << "1. Фильтрация по временному отрезку" << endl;
						cout << "2. Поиск данных по параметру" << endl;
						cout << "3. Сортировка данных по параметру" << endl;
						cout << "4. Возврат в меню работы с данными" << endl << endl;
						cout << "Выберете пункт меню" << endl;
						cin >> X;
						switch (X)
						{
						case 1:
						{
							cout << "Фильтрация данных по временному отрезку" << endl;
							ad.indiv_task(abonent_data, abonent_num_str);
						}
						case 2:
						{
							Y = 0;
							while (Y != 6)
							{
								cout << "______________________________________________________" << endl;
								cout << "                    Поиск         " << endl;
								cout << "______________________________________________________" << endl << endl;
								cout << "1. Поиск по фамилии" << endl;
								cout << "2. Поиск по имени " << endl;
								cout << "3. Поиск по отчеству " << endl;
								cout << "4. Поиск по дате" << endl;
								cout << "5. Поиск по номеру телефона" << endl;
								cout << "6. Возврат в меню пользователя" << endl << endl;
								cout << "Выберите пункт меню" << endl;
								cin >> M;
								switch (M)
								{
								case 1:
								{
									cout << "Поиск по фамилии" << endl;
									ad.finding(abonent_data, abonent_num_str, 1);
									break;
								}
								case 2:
								{
									cout << "Поиск по имени" << endl;
									ad.finding(abonent_data, abonent_num_str, 2);
									break;
								}
								case 3:
								{
									cout << "Поиск по отчеству" << endl;
									ad.finding(abonent_data, abonent_num_str, 3);
									break;
								}
								case 4:
								{
									cout << "Поиск по дате" << endl;
									ad.finding(abonent_data, abonent_num_str, 4);
									break;
								}
								case 5:
								{
									cout << "Поиск по номеру телефона" << endl;
									ad.finding(abonent_data, abonent_num_str, 5);
									break;
								}
								case 6:
								{
									break;
								}
								}
							}
							continue;
						}

						case 3:
						{	
							Y = 0;
							while (Y != 4)
							{
								cout << "______________________________________________________" << endl;
								cout << "                    Сортировка         " << endl;
								cout << "______________________________________________________" << endl << endl;
								cout << "1. Сортировка по имени " << endl;
								cout << "2. Сортировка по фамилии" << endl;
								cout << "3. Сортировка по дате" << endl;
								cout << "4. Возврат в меню обработки" << endl << endl;
								cout << "Выберите пункт меню" << endl;
								cin >> Y;
								switch (Y)
								{
								case 1:
								{
									cout << "Сортировка по имени" << endl;
									ad.sort(abonent_data, abonent_address, abonent_num_str, 1);
									break;
								}
								case 2:
								{
									cout << "Сортировка по фамилии" << endl;
									ad.sort(abonent_data, abonent_address, abonent_num_str, 2);
									break;
								}
								case 3:
								{
									cout << "Сортировка по дате" << endl;
									ad.sort(abonent_data, abonent_address, abonent_num_str, 3);
									break;
								}
								case 4:
								{
									break;
								}
								}
							}
							continue;
						}
						case 4:
						{
							break;
						}
						}
					}
					continue;
				}
				case 3: break;
				}
			}
			continue;
		}
		case 3:
		{
			role = -2;
		}

		}
	}
	while (role == 0)
	{
		User us;
		N = 0;
		while (N != 5)
		{
			cout << "______________________________________________________" << endl;
			cout << "                   Меню пользователя                " << endl;
			cout << "______________________________________________________" << endl << endl;
			cout << "1.	Просмотр всех данных" << endl;
			cout << "2.	Фильтрация по времени" << endl;
			cout << "3.	Поиск" << endl;
			cout << "4.	Сортировка" << endl;
			cout << "5.	Выход из программы" << endl << endl;
			cout << "Выберете пункт меню" << endl;
			cin >> N;
			cout << endl;
			switch (N)
			{
			case 1:
			{
				cout << "Просмотр всех данных" << endl;
				us.show_abonents(abonent_address);
				break;
			}
			case 2:
			{
				cout << "Фильтрация по времени" << endl;
				us.indiv_task(abonent_data, abonent_num_str);
				break;
			}
			case 3:
			{
				M = 0;
				while (M != 6)
				{
					cout << "______________________________________________________" << endl;
					cout << "                    Поиск         " << endl;
					cout << "______________________________________________________" << endl << endl;
					cout << "1. Поиск по фамилии" << endl;
					cout << "2. Поиск по имени " << endl;
					cout << "3. Поиск по отчеству " << endl;
					cout << "4. Поиск по дате" << endl;
					cout << "5. Поиск по номеру телефона" << endl;
					cout << "6. Возврат в меню пользователя" << endl << endl;
					cout << "Выберите пункт меню" << endl;
					cin >> M;
					switch (M)
					{
					case 1:
					{
						cout << "Поиск по фамилии" << endl;
						us.finding(abonent_data, abonent_num_str, 1);
						break;
					}
					case 2:
					{
						cout << "Поиск по имени" << endl;
						us.finding(abonent_data, abonent_num_str, 2);
						break;
					}
					case 3:
					{
						cout << "Поиск по отчеству" << endl;
						us.finding(abonent_data, abonent_num_str, 3);
						break;
					}
					case 4:
					{
						cout << "Поиск по дате" << endl;
						us.finding(abonent_data, abonent_num_str, 4);
						break;
					}
					case 5:
					{
						cout << "Поиск по номеру телефона" << endl;
						us.finding(abonent_data, abonent_num_str, 5);
						break;
					}
					case 6:
					{
						break;
					}
					}
				}
				continue;
			}
			case 4:
			{
				M = 0;
				while (M != 4)
				{
					cout << "______________________________________________________" << endl;
					cout << "                    Сортировка         " << endl;
					cout << "______________________________________________________" << endl << endl;
					cout << "1. Сортировка по имени " << endl;
					cout << "2. Сортировка по фамилии" << endl;
					cout << "3. Сортировка по дате" << endl;
					cout << "4. Возврат в меню пользователя" << endl << endl;
					cout << "Выберите пункт меню" << endl;
					cin >> M;
					switch (M)
					{
					case 1:
					{
						cout << "Сортировка по имени" << endl;
						us.sort(abonent_data, abonent_address, abonent_num_str, 1);
						break;
					}
					case 2:
					{
						cout << "Сортировка по фамилии" << endl;
						us.sort(abonent_data, abonent_address, abonent_num_str, 2);
						break;
					}
					case 3:
					{
						cout << "Сортировка по дате" << endl;
						us.sort(abonent_data, abonent_address, abonent_num_str, 3);
						break;
					}
					case 4:
					{
						break;
					}
					}
				}
				continue;
			}
			case 5:
			{
				role = -2;
			}
			}
		}

	}
	if (role == -1)
	{
		cout << "Отказано в доступе" << endl;
	}
		
		
	delete []user_data;
	delete []abonent_data;
}

int num_str(string address, int n)//Количество строк в файле
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

void making_user_array(user* user_data, int num_str)//Заполнение массива пользователей
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
				case 0: user_data[i].login = value1; break;
				case 1: user_data[i].password = value1; break;
				case 2: user_data[i].role = value1; break;
				}

				data >> value1;

			}			
		}

	}
	data.close();
}

void making_abonent_array(abonent* abonent_data, int num_str)//Заполнение массива с записями разговоров
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

int get_role(user* data, int num_str)//Получение роли
{
	string log, pass;
	int role;
	cout << "Введите ваш логин: ";
	cin >> log;
	cout << "Введите ваш пароль: ";
	cin >> pass;

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
