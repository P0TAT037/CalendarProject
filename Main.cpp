#include <iostream>
#include <conio.h>
#include "Events.h"
#include "Holidays.h"

using namespace std;

int menu(int numOfItems, string items[])
{
	int x = 0, i = 1, selection = 0;
	while (i)
	{
		system("CLS");
		cout << "                    _________________________ " << endl;
		cout << "                    |        Calendar       | " << endl;
		cout << "   =================|=======================|===================" << endl;
		cout << "   ||                     "; getDate('s'); cout << "                     ||" << endl;
		cout << "   =============================================================" << endl;
		for (int i = 0; i < numOfItems; i++)
		{
			cout << "   |                                                           |" << endl;
			cout << "   |          " << x + 1 << ". " << items[x];
			for (int i = 0; i <= (45 - items[x].length()); i++)
			{
				cout << " ";
			}
			cout << "|" << endl;;
			x += 1;
		}
		cout << "   |                                                           |" << endl;
		
		//char del = 8;
		cout << "   |____( enter a number between 1 and " << numOfItems << " to choose an item )___|" << endl;
		cout << "                            >>";
		cin >> selection;
		cin.clear();
		cin.ignore();
		if (selection <= 0 || selection > numOfItems)
		{
			system("cls");
			cout << "   _____________________________________________________________" << endl;
			cout << "   |                                                           |" << endl;
			cout << "   |      enter a number between 1 and " << numOfItems << " to choose an item     |" << endl;
			cout << "   |___________________________________________________________|" << endl;
			cout << "                 Press any button to continue . . ." << endl;
			cout << "                                 ";
			_getch();
			x = 0;
		}
		else
		{
			i = 0;
		}
	}
	return selection;
}

int main()
{
	generateEvents();

	string mainItems[8] = { "Show calendar", "Add an event","Know your sign", "Show events","Show holidays", "Know the date after",  "Help", "Exit" };

	while (1)
	{
		switch (menu(8, mainItems))
		{
		case 1:
			display();
			break;

		case 2:
			addEvent();
			break;

		case 3:
			Horo();
			break;

		case 4:
			showEvents();
			break;

		case 5:
			showHolidays();
			break;
		
		case 6:
			int n;
			system("cls");
			cout << "                    _________________________ " << endl;
			cout << "                    |        Calendar       | " << endl;
			cout << "   =================|=======================|===================" << endl;
			cout << "   ||                     "; getDate('s'); cout << "                     ||" << endl;
			cout << "   =============================================================" << endl;
			cout << "   |           Please enter the total days you want            |" << endl;
			cout << "   |                to know the date after it                  |" << endl;
			cout << "   |___________________________________________________________|" << endl;
			cout << "                         >>"; cin >> n;
			DateAfter(n);
			cout << "                  Press any button to go back. . .               " << endl;
			cout << "                                ";
			_getch();
			break;
		
		case 7:
			system("CLS");
			cout << "                    _________________________ " << endl;
			cout << "                    |        Calendar       | " << endl;
			cout << "   =================|=======================|===================" << endl;
			cout << "   ||                     "; getDate('s'); cout << "                     ||" << endl;
			cout << "   =============================================================" << endl;
			cout << "   |      While showing calendar :                             |" << endl;
			cout << "   |                                                           |" << endl;
			cout << "   |         -day number is shown in the top righy corner.     |" << endl;
			cout << "   |         -month number is shown in the bottom left corner. |" << endl;
			cout << "   |                                                           |" << endl;
			cout << "   |               -Symbols:                                   |" << endl;
			cout << "   |                       @ --> Event                         |" << endl;
			cout << "   |                       * --> Holiday                       |" << endl;
			cout << "   |                                                           |" << endl;
			cout << "   |        -if you click enter, the current display           |" << endl;
			cout << "   |         is saved at \"Calendar.txt\"                        |" << endl;
			cout << "   |                                                           |" << endl;
			cout << "   |                ------------------------                   |" << endl;
			cout << "   |       -Events you save are stord in \"SpecialDays.txt\"     |" << endl;
			cout << "   |                                                           |" << endl;
			cout << "   |                                                           |" << endl;
			cout << "   |    PS :                                                   |" << endl;
			cout << "   |          ANY FILE SHOULD NOT BE MODIFIED OR DELETED       |" << endl;
			cout << "   =============================================================" << endl;
			cout << "                  Press any button to go back. . .               " << endl;
			cout << "                                ";
			_getch();
			break;

		case 8:
			exit(0);
		}
	}

	return 0;
}
