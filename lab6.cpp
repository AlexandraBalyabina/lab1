
#include <iostream>
#include <fstream>
#include <iomanip>
#include <clocale>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <Windows.h>
#include "participant.h"
#include "competition.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	string acity;
	int num, j, add, del;
	bool exit = true;
	competition my_comp(25, 15);
	my_comp.read("my_participant.txt");
	participant part2("Терек", "Грозный", "Р.Рахимов", 1958, 15820000, 14, 19);
	awards part1("Ротор", "Волгоград", "С.Павлов", 1929, 1620000, 17, 18, 3, 5);
	do {
		SetConsoleCP(866);
		cout << "\n=================================================================" << endl;
		cout << "Выберите:" << endl;
		cout << "1) Вывод на экран информацию о всех командах" << endl;
		cout << "2) Поиск команды по городу" << endl;
		cout << "3) Поиск команды с высоким отношением очков к бюджету" << endl;
		cout << "4) Добавить команду" << endl;
		cout << "5) Добавить производный класс" << endl;
		
		cin >> num;
		switch (num)
		{
		case 1:
			cout << my_comp;
			break;
		case 2:
			cout << "Введите название города" << endl;
			SetConsoleCP(1251);
			cin >> acity;
			my_comp.find_participant(acity);
			break;
		case 3:

			my_comp.display_participant();
			break;
		case 4:
		{
			cout << "Как вы хотите добавить команду" << endl;
			cout << "1) Вручную " << endl;
			cout << "2) Автоматически" << endl;
			cin >> add;
			switch (add)
			{
			case 1:
				my_comp.plus_participant("my_participant.txt");
				break;
			case 2:
				my_comp += part2;
				break;
			default:
				break;
			}
			break;
		}
		case 5:
			my_comp += part1;
			break;
		case 6:
			SetConsoleCP(866);
			cout << "Введите номер команды которую хотите удалить" << endl;
			cout << "1) Базового класса\n 2) Производного класса" << endl;
			cin >> del;
			if (del == 1)
			{
				cout << "Введите номер команды которую хотите удалить" << endl;
				cin >> j;
				my_comp -= (j);
			}
			if (del == 2)
			{
				double j;
				cout << "Введите номер команды которую хотите удалить" << endl;
				cin >> j;
				my_comp -= j;
			}
			break;
		case 7:

			my_comp.write_participant_to_file("participant.txt");
			break;
		case 8:
			exit = false;
			break;
		default:
			break;
		}
	} while (exit);

	system("pause");
}