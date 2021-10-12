#include <fstream>
#include <conio.h>
#include <string>
#include <sstream>
#include "Events.h"
#include "Holidays.h"

vector <Event> events;

Event::Event()
{
	Day.set(1, 1, 3200);
	location = "";
	name = "";
}

int Event::get(char r)
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

string Event::Get(char r)
{
	switch (r)
	{
	case 'n':
		return name;
	case 'l':
		return location;
	}
}

void Event::set(int d, int m, int y, string n, string l)
{
	Day.set(d, m, y);
	location = l;
	name = n;
}

int Event::daysLeft() {
	int n, result = 0;
	if (Day.month.number == MONTH + 1) {
		result = result + (monthDaysNum(MONTH) - DAY);
		result = result + Day.get('d');
		return result;
	}
	else if ((Day.month.number > MONTH) && (Day.month.number > MONTH + 1)) {
		n = Day.month.number - MONTH;
		for (int i = 1; i < n; i++) {
			result = result + monthDaysNum(MONTH + i);
		}
		result = result + (monthDaysNum(MONTH) - DAY);
		result = result + Day.get('d');
		return result;
	}
	else if (Day.month.number == MONTH) {
		if (Day.get('d') > DAY)
		{
			return Day.get('d') - DAY;

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

void addEvent()
{
	int d, m, y;
	string l, n;
	ofstream fout("specialDays.txt", ios::app);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();
	system("cls");
	cout << "   _____________________________________________________________" << endl;
	cout << "   |              Please enter the name of the event           |" << endl;
	cout << "   |___________________________________________________________|" << endl;
	cout << "                    >>"; getline(cin, n);


	system("cls");
	cout << "   _____________________________________________________________" << endl;
	cout << "   |           Please enter the location of the event          |" << endl;
	cout << "   |___________________________________________________________|" << endl;
	cout << "                   >>"; getline(cin, l);

	system("cls");
	cout << "   _____________________________________________________________" << endl;
	cout << "   |             Please enter the day of the event             |" << endl;
	cout << "   |___________________________________________________________|" << endl;
	cout << "                             >>"; cin >> d;


	system("cls");
	cout << "   _____________________________________________________________" << endl;
	cout << "   |             Please enter the month of the event           |" << endl;
	cout << "   |___________________________________________________________|" << endl;
	cout << "                            >>"; cin >> m;

	system("cls");
	cout << "   _____________________________________________________________" << endl;
	cout << "   |             Please enter the year of the event            |" << endl;
	cout << "   |___________________________________________________________|" << endl;
	cout << "                            >>"; cin >> y;

	Event date(d, m, y, n, l);
	events.push_back(date);
	fout << n << ":\n"
		<< date.get('d') << "/" << date.get('m') << "/" << date.get('y') << endl
		<< "at:" << endl << l << endl
		<< "====================================================================" << endl;
	fout.close();
}

void showEvents()
{
	system("cls");
	cout << "                    _________________________ " << endl;
	cout << "                    |        Calendar       | " << endl;
	cout << "   =================|=======================|===================" << endl;
	cout << "   ||                     "; getDate('s'); cout << "                     ||" << endl;
	cout << "   =============================================================" << endl;

	for (int i = 1; i < events.size(); i++)
	{
		string s = events[i].Get('n') + ": ";
		s += to_string(events[i].get('d')) + '/' + to_string(events[i].get('m')) + '/' + to_string(events[i].get('y'));

		cout << "   |                                                           |" << endl;

		cout << "   |               " << s;
		for (int i = 0; i < 46 - s.length(); i++)
		{
			cout << " ";
		} cout << "|" << endl;


		cout << "   |               at: " << events[i].Get('l');
		int tmp = 40 - events[i].Get('l').size();
		for (int i = 0; i < tmp; i++)
		{
			cout << " ";
		} cout << "|" << endl;

		if (events[i].daysLeft() == 0)
		{

			cout << "   |               today                                       |" << endl;
		}
		else if (events[i].daysLeft() == -1)
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
			cout << events[i].daysLeft() << " days left";
			tmp = (35 - (log10(events[i].daysLeft()) + 1));
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

void generateEvents()
{
	Event BIRTHDAY;
	ifstream fin("birthday.dat");
	ofstream fout;
	string temp, name, location;
	int data[3];
	if (fin >> temp)
	{
		stringstream s(temp);
		string tmp, arr[3];
		int i = 0;

		while (getline(s, tmp, '/'))
		{
			arr[i] = tmp;
			i++;
		}
		BIRTHDAY.set(stoi(arr[0]), stoi(arr[1]), YEAR, "Birthday", " ");
		if (events.empty())
		{
			events.push_back(BIRTHDAY);
		}
		fin.close();
	}
	else
	{
		string tmp, arr[3];
		fin.close();
		fout.open("birthday.dat");
		cout << "                    _________________________ " << endl;
		cout << "                    |        Calendar       | " << endl;
		cout << "   =================|=======================|===================" << endl;
		cout << "   ||                     "; getDate('s'); cout << "                     ||" << endl;
		cout << "   =============================================================" << endl;
		cout << "   |                Please Enter your birth day                |" << endl;
		cout << "   |___________________________________________________________|" << endl;
		cout << "                           >>"; cin >> arr[0];
		fout << arr[0] << "/";

		system("cls");
		cout << "                    _________________________ " << endl;
		cout << "                    |        Calendar       | " << endl;
		cout << "   =================|=======================|===================" << endl;
		cout << "   ||                     "; getDate('s'); cout << "                     ||" << endl;
		cout << "   =============================================================" << endl;
		cout << "   |               Please Enter your birth month               |" << endl;
		cout << "   |___________________________________________________________|" << endl;
		cout << "                           >>"; cin >> arr[1];
		fout << arr[1] << "/";

		system("cls");
		cout << "                    _________________________ " << endl;
		cout << "                    |        Calendar       | " << endl;
		cout << "   =================|=======================|===================" << endl;
		cout << "   ||                     "; getDate('s'); cout << "                     ||" << endl;
		cout << "   =============================================================" << endl;
		cout << "   |                Please Enter your birth year               |" << endl;
		cout << "   |___________________________________________________________|" << endl;
		cout << "                           >>"; cin >> arr[2];
		fout << arr[2];
		fout.close();

		BIRTHDAY.set(stoi(arr[0]), stoi(arr[1]), YEAR, "Birthday", " ");
		events.push_back(BIRTHDAY);
		fin.close();
		generateEvents();
		return;
	}

	fin.close();
	ifstream finn("SpecialDays.txt");
	string tmp;
	finn >> tmp;
	if (tmp != "")
	{
		finn.ignore(numeric_limits<streamsize>::max(), '\n');
		finn.clear();
		while (!finn.eof())
		{
			//getline(finn, tmp);
			name = tmp + '\b';
			for (int i = 0; i < 2; i++)
			{
				getline(finn, tmp, '/');
				data[i] = stoi(tmp);
			}
			getline(finn, tmp);
			data[2] = stoi(tmp);
			getline(finn, tmp);
			getline(finn, location);
			getline(finn, tmp);
			getline(finn, tmp);
			Event event(data[0], data[1], data[2], name, location);
			events.push_back(event);
		}
	}
}

void generateDays(Date Days[35])
{
	Holiday xmas(7, 1, "X-MAS");
	Holiday PDJR(25, 1, "Police Day and January 25 Revolution");
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
	Holiday holidays[13] = { xmas, PDJR, Sinai, Labor, Easter, eid, Revolution, Arafat, Eid, revolution, Islamic, Forces, Birthday };

	Date tmp(sat(DAY), MONTH);

	for (int i = 0; i < 35; i++)
	{
		Days[i].set(tmp.get('d'), tmp.get('m'), tmp.get('y'));
		tmp = tmp + 1;
	}

	for (int i = 0; i < 35; i++)
	{
		for (int n = 0; n < 13; n++)
		{
			if (Days[i].get('d') == holidays[n].get('d') && Days[i].get('m') == holidays[n].get('m') && Days[i].get('y') == holidays[n].get('y'))
			{
				Days[i].sign = '*';
			}
		}
	}

	for (int i = 0; i < 35; i++)
	{
		for (int n = 0; n < events.size(); n++)
		{
			if (Days[i].get('d') == events[n].get('d') && Days[i].get('m') == events[n].get('m') && Days[i].get('y') == events[n].get('y'))
			{
				Days[i].sign = '@';
			}
		}
	}
}

string Event::Horoscope()
{
	if ((Day.get('d') >= 21) && (Day.get('m') == 3) || (Day.get('d') <= 20) && (Day.get('m') == 4))
	{
		return "Your horoscope is ARIES";
	}
	else if ((Day.get('d') >= 21) && (Day.get('m') == 4) || (Day.get('d') <= 21) && (Day.get('m') == 5))
	{
		return "Your horoscope is TAURUS";
	}
	else if ((Day.get('d') >= 22) && (Day.get('m') == 5) || (Day.get('d') <= 21) && (Day.get('m') == 6))
	{
		return "Your horoscope is GEMINI";
	}
	else if ((Day.get('d') >= 22) && (Day.get('m') == 6) || (Day.get('d') <= 22) && (Day.get('m') == 7))
	{
		return "Your horoscope is CANCER";
	}
	else if ((Day.get('d') >= 23) && (Day.get('m') == 7) || (Day.get('d') <= 22) && (Day.get('m') == 8))
	{
		return "Your horoscope is LEO";
	}
	else if ((Day.get('d') >= 23) && (Day.get('m') == 8) || (Day.get('d') <= 22) && (Day.get('m') == 9))
	{
		return "Your horoscope is VIRGO";
	}
	else if ((Day.get('d') >= 23) && (Day.get('m') == 9) || (Day.get('d') <= 22) && (Day.get('m') == 10))
	{
		return "Your horoscope is LIBRA";
	}
	else if ((Day.get('d') >= 23) && (Day.get('m') == 10) || (Day.get('d') <= 21) && (Day.get('m') == 11))
	{
		return "Your horoscope is SCORPIO";
	}
	else if ((Day.get('d') >= 22) && (Day.get('m') == 11) || (Day.get('d') <= 21) && (Day.get('m') == 12))
	{
		return "Your horoscope is SAGITITRIUS";
	}
	else if ((Day.get('d') >= 22) && (Day.get('m') == 12) || (Day.get('d') <= 30) && (Day.get('m') == 1))
	{
		return "Your horoscope is CAPRICORN";
	}
	else if ((Day.get('d') >= 21) && (Day.get('m') == 1) || (Day.get('d') <= 19) && (Day.get('m') == 2))
	{
		return "Your horoscope is AQUARIUS";
	}
	else if ((Day.get('d') >= 20) && (Day.get('m') == 2) || (Day.get('d') <= 30) && (Day.get('m') == 3))
	{
		return "Your horoscope is PISCES";
	}
	else
	{
		return "Invalid Input";
	}
}

string getHoro()
{
	return events[0].Horoscope();
}

void Horo()
{
	char a;
	system("cls");
	cout << "                    _________________________ " << endl;
	cout << "                    |        Calendar       | " << endl;
	cout << "   =================|=======================|===================" << endl;
	cout << "   ||                     "; getDate('s'); cout << "                     ||" << endl;
	cout << "   =============================================================" << endl;
	cout << "   |           Enter 1 to know your sign                       |" << endl;
	cout << "   |                 2 to know the sign of another birthday    |" << endl;
	cout << "   |___________________________________________________________|" << endl;
	cout << "                           >>"; cin >> a;

	if (a == '1')
	{

		system("CLS");
		cout << "                    _________________________ " << endl;
		cout << "                    |        Calendar       | " << endl;
		cout << "   =================|=======================|===================" << endl;
		cout << "   ||                     "; getDate('s'); cout << "                     ||" << endl;
		cout << "   =============================================================" << endl;
		cout << "   |                                                           |" << endl;
		string s = getHoro();
		cout << "   | ";
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
		cout << " |" << endl;
		cout << "   |                                                           |" << endl;
		cout << "   =============================================================" << endl;
		cout << "                  Press any button to go back. . .               " << endl;
		cout << "                                ";
		_getch();

	}
	else if (a == '2')
	{
		int b;
		system("cls");
		cout << "                    _________________________ " << endl;
		cout << "                    |        Calendar       | " << endl;
		cout << "   =================|=======================|===================" << endl;
		cout << "   ||                     "; getDate('s'); cout << "                     ||" << endl;
		cout << "   =============================================================" << endl;
		cout << "   |               Enter the number of event                   |" << endl;
		cout << "   |___________________________________________________________|" << endl;
		cout << "                           >>"; cin >> b;

		system("CLS");
		cout << "                    _________________________ " << endl;
		cout << "                    |        Calendar       | " << endl;
		cout << "   =================|=======================|===================" << endl;
		cout << "   ||                     "; getDate('s'); cout << "                     ||" << endl;
		cout << "   =============================================================" << endl;
		cout << "   |                                                           |" << endl;
		cout << "   |";
		string s = events[b].Horoscope();
		for (int i = 0; (i < 29 - (s.length()) / 2); i++)
		{
			cout << ' ';
		}
		cout << s;
		if (s.length() % 2 == 0)
		{
			for (int i = 0; (i < 30 - (s.length()) / 2); i++)
			{
				cout << ' ';
			}
		}
		else
		{
			for (int i = 0; (i < 29 - (s.length()) / 2); i++)
			{
				cout << ' ';
			}
		}
		cout << "|" << endl;
		cout << "   |                                                           |" << endl;
		cout << "   =============================================================" << endl;
		cout << "                  Press any button to go back. . .               " << endl;
		cout << "                                ";
		_getch();

	}
	else
	{
		while (a != '1' && a != '2')
		{
			cout << "                    _________________________ " << endl;
			cout << "                    |        Calendar       | " << endl;
			cout << "   =================|=======================|===================" << endl;
			cout << "   ||                     "; getDate('s'); cout << "                     ||" << endl;
			cout << "   =============================================================" << endl;
			cout << "   |                    Please enter 1 or 2                    |" << endl;
			cout << "   |___________________________________________________________|" << endl;
			cout << "                           >>"; cin >> a;
		}
	}

}