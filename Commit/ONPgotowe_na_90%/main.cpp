#ifndef bib
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>
#include <stack>
#include <vector>
#define PI 3.14159265
using namespace std;
#define bib
#endif
#include "Conwerter.h"





int main()
{
	string exp;
	vector<string> result;
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
			for(unsigned int i=0;i<result.size();i++)
			{
				cout << result[i] << " ";
			}
			cout << endl;
		}

		if (!con.licz())
		{
			cout << "Wynik = " << con.Parser(result, 1, 2) << endl;
		}
		cout << "e - wyjscie LUB dowolny klawisz - wprowadz funkcje" << endl;
		key = getch();
		system("cls");
	}
}