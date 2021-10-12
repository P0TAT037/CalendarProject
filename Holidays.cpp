#include <conio.h>
#include "Holidays.h"

Holiday::Holiday()
{
	Day.set(1, 1, 3200);
	name = "";
}

int Holiday::get(char r)
{
	switch (r)
	{
	case 'd':
		return Day.get('d');
		break;

	case 'm':
		return Day.get('m');
		break;

	case 'y':
		return Day.get('y');
		break;
	}
}

string Holiday::Get()
{
	return Holiday::name;
}

int Holiday::daysLeft() {
	int n, result = 0;
	if (Day.month.number == MONTH + 1) {
		result = result + (monthDaysNum(MONTH) - DAY);
		result = result + (Day.get('d') - 1);
		return result;
	}
	else if ((Day.month.number > MONTH) && (Day.month.number > MONTH + 1)) {
		n = Day.month.number - MONTH;
		for (int i = 1; i < n; i++) {
			result = result + monthDaysNum(MONTH + i);
		}
		result = result + (monthDaysNum(MONTH) - DAY);
		result = result + (Day.get('d') - 1);
		return result;
	}
	else if (Day.month.number == MONTH) {
		if (Day.get('d') > DAY)
		{
			return Day.get('d') - DAY - 1;

		}
		else if (Day.get('d') == DAY)
		{
			return 0;
		}
		else
		{
			return -1;
		}

	}
}

void showHolidays()
{
	Holiday xmas(7, 1, "X-MAS");
	Holiday JR(25, 1, "January 25 Revolution");
	Holiday Sinai(25, 4, "Sinai Liberation day");
	Holiday Labor(1, 5, "Labor Day");
	Holiday Easter(3, 5, "EasterDay");
	Holiday eid(13, 5, "Eid Al-Fitr");
	Holiday Revolution(30, 6, "Revolution June 30");
	Holiday Arafat(19, 7, "Day of Arafat");
	Holiday Eid(20, 7, "Eid Al-Adha");
	Holiday revolution(23, 7, "Revolution holiday");
	Holiday Islamic(9, 8, "Islamic New Year");
	Holiday Forces(6, 10, "Armed Forces Day");
	Holiday Birthday(18, 10, "Prophet's Birthday");
	Holiday holidays[13] = { xmas, JR, Sinai, Labor, Easter, eid, Revolution, Arafat, Eid, revolution, Islamic, Forces, Birthday };

	system("cls");
	cout << "                    _________________________ " << endl;
	cout << "                    |        Calendar       | " << endl;
	cout << "   =================|=======================|===================" << endl;
	cout << "   ||                     "; getDate('s'); cout << "                     ||" << endl;
	cout << "   =============================================================" << endl;

	for (int i = 0; i < 13; i++)
	{
		string s = holidays[i].Get() + ": ";
		s += to_string(holidays[i].get('d')) + '/' + to_string(holidays[i].get('m')) + '/' + to_string(holidays[i].get('y'));

		cout << "   |                                                           |" << endl;

		cout << "   |               " << s;
		for (int i = 0; i < 44 - s.length(); i++)
		{
			cout << " ";
		} cout << "|" << endl;

		if (holidays[i].daysLeft() == 0)
		{

			cout << "   |               today                                       |" << endl;
		}
		else if (holidays[i].daysLeft() == -1)
		{
			cout << "   |               Passed                                      |" << endl;
		}
		else
		{
			cout << "   |";
			for (int i = 0; i < 15; i++)
			{
				cout << " ";
			}
			cout << holidays[i].daysLeft() << " days left";
			int tmp = (35 - (log10(holidays[i].daysLeft()) + 1));
			for (int i = 0; i < tmp; i++)
			{
				cout << " ";
			}
			cout << "|" << endl;
		}
		cout << "   |                                                           |" << endl;
		cout << "   |     ==============================================        |" << endl;

	}

	cout << "                  Press any button to go back. . .               " << endl;
	cout << "                                ";
	_getch();
}