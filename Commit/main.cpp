#include <cstdlib>
#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>
#include "MathParser.hpp" //klasa

using namespace std;

float _dodawanie(float arg1, float arg2)
{
   return arg1 + arg2;
}

float _odejmowanie(float arg1, float arg2)
{
   return arg1 - arg2;
}

float _mnozenie(float arg1, float arg2)
{
   return arg1 * arg2;
}

float _dzielenie(float arg1, float arg2)
{
   return arg1 / arg2;
}

int main(int argc, char *argv[])
{
   string exp;
   char key;

   while(key != 'e')
   {
    exp = "0";

   cout << "PARSER gumis v0.3" << endl << endl;
   cout << "f(x) = ";
   cin >> exp;

   math_parser mp;
   mp.AddOperator("+", 1, (direction)0, _dodawanie);
   mp.AddOperator("-", 1, (direction)0, _odejmowanie);
   mp.AddOperator("*", 2, (direction)0, _mnozenie);
   mp.AddOperator("/", 2, (direction)0, _dzielenie);
   float ret = mp.Parse(exp);
   cout << "WYNIK = " << ret << endl << endl;
   cout << "e - wyjscie LUB dowolny klawisz - wprowadz funkcje" << endl;
   key = getch();
   system("cls");
   }
   return EXIT_SUCCESS;
}

