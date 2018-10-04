
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
	111111111
		22
		
	setlocale(LC_ALL, "rus");
	string acity;
	int num, j, add, del;
	bool exit = true;
	competition my_comp(25, 15);
	my_comp.read("my_participant.txt");
	participant part2("Òåðåê", "Ãðîçíûé", "Ð.Ðàõèìîâ", 1958, 15820000, 14, 19);
	awards part1("Ðîòîð", "Âîëãîãðàä", "Ñ.Ïàâëîâ", 1929, 1620000, 17, 18, 3, 5);
	do {
		SetConsoleCP(866);
		cout << "\n=================================================================" << endl;
		cout << "Âûáåðèòå:" << endl;
		cout << "1) Âûâîä íà ýêðàí èíôîðìàöèþ î âñåõ êîìàíäàõ" << endl;
		cout << "2) Ïîèñê êîìàíäû ïî ãîðîäó" << endl;
		cout << "3) Ïîèñê êîìàíäû ñ âûñîêèì îòíîøåíèåì î÷êîâ ê áþäæåòó" << endl;
		cout << "4) Äîáàâèòü êîìàíäó" << endl;
		cout << "5) Äîáàâèòü ïðîèçâîäíûé êëàññ" << endl;
		
		cin >> num;
		switch (num)
		{
		case 1:
			cout << my_comp;
			break;
		case 2:
			cout << "Ââåäèòå íàçâàíèå ãîðîäà" << endl;
			SetConsoleCP(1251);
			cin >> acity;
			my_comp.find_participant(acity);
			break;
		case 3:

			my_comp.display_participant();
			break;
		case 4:
		{
			cout << "Êàê âû õîòèòå äîáàâèòü êîìàíäó" << endl;
			cout << "1) Âðó÷íóþ " << endl;
			cout << "2) Àâòîìàòè÷åñêè" << endl;
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
			cout << "Ââåäèòå íîìåð êîìàíäû êîòîðóþ õîòèòå óäàëèòü" << endl;
			cout << "1) Áàçîâîãî êëàññà\n 2) Ïðîèçâîäíîãî êëàññà" << endl;
			cin >> del;
			if (del == 1)
			{
				cout << "Ââåäèòå íîìåð êîìàíäû êîòîðóþ õîòèòå óäàëèòü" << endl;
				cin >> j;
				my_comp -= (j);
			}
			if (del == 2)
			{
				double j;
				cout << "Ââåäèòå íîìåð êîìàíäû êîòîðóþ õîòèòå óäàëèòü" << endl;
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
