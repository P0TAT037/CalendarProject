#include <string>
#include <fstream>
#include <conio.h>
#include "Date.h"
#include "Events.h"
#include "Holidays.h"

int getDate(char dtype)
{
	//takes a char input...
	// 'm' : returns the current month
	// 'd' : returns the current day
	// 'y' : returns the current year
	// 'n' : returns 0 and prints the current day name
	// else : returns 0 and prints the current full date

	string date, day, nd;
	string tmp1, tmp2, tmp3;
	int d, m, y;

	system("date /t > tmp.dat");
	ifstream fin("tmp.dat");

	getline(fin, date);

	for (int i = 0; i < 14; i++)
	{
		if (i < 3)
		{
			day += date[i];
		}
		else
		{
			nd += date[i];
		}
	}

	m = stoi(nd.substr(0, 3));
	d = stoi(nd.substr(4, 5));
	y = stoi(nd.substr(7, 10));

	fin.close();
	system("del tmp.dat");

	if (dtype == 'm')
	{
		return m;
	}
	else if (dtype == 'd')
	{
		return d;
	}
	else if (dtype == 'y')
	{
		return y;
	}
	else if (dtype == 'n')
	{
		cout << day;
		return 0;
	}
	else
	{
		cout << date;
		return 0;
	}


}

void DateAfter(int n)
{
	int result, month, year;
	while ((n > 0) && (n <= 1000))
	{
		if (n + DAY > monthDaysNum(MONTH))
		{
			result = monthDaysNum(MONTH) - DAY;
			result = n - result;
			month = MONTH + 1;
			year = YEAR;
			while (result > monthDaysNum(month))
			{
				result = result - monthDaysNum(month);
				month = month + 1;
				if (month > 12)
				{
					month = 1;
					year = year + 1;
				}
			}
			system("cls");
			string s = "The date after " + to_string(n) + " days from today:";
			cout << "                    _________________________ " << endl;
			cout << "                    |        Calendar       | " << endl;
			cout << "   =================|=======================|===================" << endl;
			cout << "   ||                     "; getDate('s'); cout << "                     ||" << endl;
			cout << "   =============================================================" << endl;
			cout << "   ||";
			for (int i = 0; (i < 28 - (s.length()) / 2); i++)
			{
				cout << ' ';
			}
			cout << s;
			if (s.length() % 2 == 0)
			{
				for (int i = 0; (i < 29 - (s.length()) / 2); i++)
				{
					cout << ' ';
				}
			}
			else
			{
				for (int i = 0; (i < 28 - (s.length()) / 2); i++)
				{
					cout << ' ';
				}
			}
			cout << "||" << endl;
			s = to_string(result) + '/' + to_string(month) + '/' + to_string(year);
			cout << "   ||";
			for (int i = 0; (i < 28 - (s.length()) / 2); i++)
			{
				cout << ' ';
			}
			cout << s;
			if (s.length() % 2 == 0)
			{
				for (int i = 0; (i < 29 - (s.length()) / 2); i++)
				{
					cout << ' ';
				}
			}
			else
			{
				for (int i = 0; (i < 28 - (s.length()) / 2); i++)
				{
					cout << ' ';
				}
			}
			cout << "||" << endl;
			cout << "   ||_________________________________________________________||" << endl;
		}
		else
		{
			system("cls");
			string s = "The date after " + to_string(n) + " days from today:";
			cout << "                    _________________________ " << endl;
			cout << "                    |        Calendar       | " << endl;
			cout << "   =================|=======================|===================" << endl;
			cout << "   ||                     "; getDate('s'); cout << "                     ||" << endl;
			cout << "   =============================================================" << endl;
			//cout << "   ||         The date after " << n << " days from today:" << "   ||" << endl;
			//cout << "   ||             " << MONTH << "/" << getDate('d') + n << "/" << YEAR << "        ||" << endl;
			cout << "   ||";
			for (int i = 0; (i < 28 - (s.length()) / 2); i++)
			{
				cout << ' ';
			}
			cout << s;
			if (s.length() % 2 == 0)
			{
				for (int i = 0; (i < 29 - (s.length()) / 2); i++)
				{
					cout << ' ';
				}
			}
			else
			{
				for (int i = 0; (i < 28 - (s.length()) / 2); i++)
				{
					cout << ' ';
				}
			}
			cout << "||" << endl;
			s = to_string(MONTH) + '/' + to_string(getDate('d') + n) + '/' + to_string(YEAR);
			cout << "   ||";
			for (int i = 0; (i < 28 - (s.length()) / 2); i++)
			{
				cout << ' ';
			}
			cout << s;
			if (s.length() % 2 == 0)
			{
				for (int i = 0; (i < 29 - (s.length()) / 2); i++)
				{
					cout << ' ';
				}
			}
			else
			{
				for (int i = 0; (i < 28 - (s.length()) / 2); i++)
				{
					cout << ' ';
				}
			}
			cout << "||" << endl;
			cout << "   ||_________________________________________________________||" << endl;
		}
		break;
	}

}

string getDay()
{
	string  day, date;

	system("date /t > tmp.dat");
	ifstream fin("tmp.dat");

	getline(fin, date);

	for (int i = 0; i < 3; i++)
	{
		day += date[i];
	}

	fin.close();
	system("del tmp.dat");

	return day;
}

string monthName()
{
	switch (MONTH)
	{
	case 1:
		return "January";
		break;

	case 2:
		return "February";
		break;

	case 3:
		return "March";
		break;

	case 4:
		return "April";
		break;

	case 5:
		return "May";
		break;

	case 6:
		return "June";
		break;

	case 7:
		return "July";
		break;

	case 8:
		return "August";
		break;

	case 9:
		return "September";
		break;

	case 10:
		return "October";
		break;

	case 11:
		return "November";
		break;

	case 12:
		return "December";
		break;

	default:
		return "NULL";
		break;
	};
}

string monthName(int i)
{
	switch (i)
	{
	case 1:
		return "January";
		break;

	case 2:
		return "February";
		break;

	case 3:
		return "March";
		break;

	case 4:
		return "April";
		break;

	case 5:
		return "May";
		break;

	case 6:
		return "June";
		break;

	case 7:
		return "July";
		break;

	case 8:
		return "August";
		break;

	case 9:
		return "September";
		break;

	case 10:
		return "October";
		break;

	case 11:
		return "November";
		break;

	case 12:
		return "December";
		break;

	default:
		return "";
		break;
	}
}

int monthDaysNum()
{
	switch (MONTH)
	{
	case 2:
		return 28;
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;

	default:
		return 31;
		break;
	}
}

int monthDaysNum(int m)
{
	switch (m)
	{
	case 2:
		return 28;
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;

	default:
		return 31;
		break;
	}
}

int sat(int d)
{

	if (DAYNAME == "Sat")
	{
		return d;
	}
	else if (DAYNAME == "Sun")
	{
		if (d - 1 >= 1)
		{
			return d - 1;
		}
		else
		{
			return monthDaysNum(MONTH - 1);
		}
	}
	else if (DAYNAME == "Mon")
	{
		if (d - 2 >= 1)
		{
			return d - 2;
		}
		else
		{
			return monthDaysNum(MONTH - 1) - 1;
		}
	}
	else if (DAYNAME == "Tue")
	{
		if (d - 3 >= 1)
		{
			return d - 3;
		}
		else
		{
			return monthDaysNum(MONTH - 1) - 2;
		}
	}
	else if (DAYNAME == "Wed")
	{
		if (d - 4 >= 1)
		{
			return d - 4;
		}
		else
		{
			return monthDaysNum(MONTH - 1) - 3;
		}
	}
	else if (DAYNAME == "Thu")
	{
		if (d - 5 >= 1)
		{
			return d - 5;
		}
		else
		{
			return monthDaysNum(MONTH - 1) - 4;
		}
	}
	else if (DAYNAME == "Fri")
	{
		if (d - 6 >= 1)
		{
			return d - 6;
		}
		else
		{
			return monthDaysNum(MONTH - 1) - 5;
		}
	}
	else
	{
		return 0;
	}
}



void display()
{
	system("cls");
	Date today;
	Date Days[35];
	int s;
	generateDays(Days);

	cout << "=====================================================================================" << endl;
	cout << "||";
	for (int i = 0; i < (82 - today.month.name.length()) / 2; i++)
	{
		cout << " ";
	}
	cout << today.month.name;
	for (int i = 0; i < ((83 - today.month.name.length()) / 2) - 1; i++)
	{
		cout << " ";
	}
	cout << "||" << endl;

	cout << "=====================================================================================" << endl;
	cout << "|    Sat    |    Sun    |    Mon    |    Tue    |    Wed    |    Thu    |    Fri    |" << endl;
	cout << "=====================================================================================" << endl;

	for (int j = 0; j < 35; j)
	{
		cout << "|";
		for (int i = 1; i <= 7; i++)
		{

			if (Days[j].get('d') < 10)
			{
				cout << "          " << Days[j].get('d') << "|";
				j++;
			}
			else
			{
				cout << "         " << Days[j].get('d') << "|";
				j++;
			}
		}
		cout << endl;

		for (int k = 0; k < 7; k++)
		{
			cout << "|           ";
		}
		cout << "|" << endl;

		s = j - 7;
		for (s; s < j; s++)
		{
			cout << "|     " << Days[s].sign << "     ";
		}
		cout << "|" << endl;

		for (int k = 0; k < 7; k++)
		{
			cout << "|           ";
		}

		cout << "|\n|";

		s = j - 7;
		for (s; s < j; s++)
		{
			if (Days[s].month.number < 10)
			{
				cout << Days[s].month.number << "__________|";
			}
			else
			{
				cout << Days[s].month.number << "_________|";
			}
		}
		cout << endl;
	}

	cout << endl;
	cout << "                 >>click enter to save the calander or esc to exit<<" << endl;
	cout << "                                          ";
	char e = 0;
	while (e != 27 && e != 13)
	{
		e = _getch();
	}
	if (e == 13)
	{
		ofstream fout("Calendar.txt", ios::app);
		fout << "=====================================================================================" << endl;
		fout << "||";

		for (int i = 0; i < (82 - today.month.name.length()) / 2; i++)
		{
			fout << " ";
		}
		fout << today.month.name;
		for (int i = 0; i < ((83 - today.month.name.length()) / 2) - 1; i++)
		{
			fout << " ";
		}

		fout << "||" << endl;
		fout << "=====================================================================================" << endl;
		fout << "|    Sat    |    Sun    |    Mon    |    Tue    |    Wed    |    Thu    |    Fri    |" << endl;
		fout << "=====================================================================================" << endl;

		for (int j = 0; j < 35; j)
		{

			fout << "|";

			for (int i = 1; i <= 7; i++)
			{

				if (Days[j].get('d') < 10)
				{
					fout << "          " << Days[j].get('d') << "|";
					j++;
				}
				else
				{
					fout << "         " << Days[j].get('d') << "|";
					j++;
				}
			}
			fout << endl;



			for (int k = 0; k < 7; k++)
			{
				fout << "|           ";
			}
			fout << "|" << endl;

			s = j - 7;
			for (s; s < j; s++)
			{
				fout << "|     " << Days[s].sign << "     ";

			}
			fout << "|" << endl;

			for (int k = 0; k < 7; k++)
			{
				fout << "|           ";
			}

			fout << "|\n|";

			s = j - 7;
			for (s; s < j; s++)
			{
				if (Days[s].month.number < 10)
				{
					fout << Days[s].month.number << "__________|";
				}
				else
				{
					fout << Days[s].month.number << "_________|";
				}
			}
			fout << endl;
		}
	}
}



Date::Date()
{
	day = DAY;
	year = 2021;
	month.days = monthDaysNum(MONTH);
	month.name = monthName(MONTH);
	month.number = MONTH;
}



int Date::get(char r)
{
	switch (r)
	{
	case 'd':
		return day;
		break;

	case 'm':
		return month.number;
		break;

	case 'y':
		return year;
		break;
	}
}