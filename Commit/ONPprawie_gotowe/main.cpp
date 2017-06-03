#ifndef bib
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>
#include <stack>
#include <queue>
using namespace std;
#define bib
#endif
#include "Conwerter.h"





int main()
{
	string exp;
	queue<string> result;
	char key='a';
	while (key != 'e')
	{
		cout << "Wpisz wyrazenie: ";
		Conwerter con;
		getline(cin, exp);
		result = con.ONP(exp);
		if (con.blad() != 0)
		{
			cout << "Error nr: " << con.blad() << endl;
		}
		else
		{
			cout << "Zapis w postaci ONP:" << endl;
			while (!result.empty())
			{
				cout << result.front() << " ";
				result.pop();
			}
			cout << endl;
		}
		cout << "e - wyjscie LUB dowolny klawisz - wprowadz funkcje" << endl;
		key = getch();
		system("cls");
	}
}