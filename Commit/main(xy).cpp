#include <cstdlib>
#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>
#include "MathParser.hpp" //klasa

using namespace std;

float _potegowanie(float arg1, float arg2)
{
    return pow(arg1, arg2);
}

float _pierwiastkowanie(float arg1, float arg2)
{
    if(arg2 < 2) return arg1;
    else if(arg2 == 2) return sqrt(arg1);
    else if (arg2 > 2)
    {
        float ulamek = 1 / arg2;
        return pow(arg1, ulamek);
    }
}

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

   cout << "PARSER gumis v0.5.1" << endl << endl;
   cout << "f(x) = ";
   cin >> exp;

   math_parser mp;
   mp.AddOperator("+", 1, (direction)0, _dodawanie);
   mp.AddOperator("-", 1, (direction)0, _odejmowanie);
   mp.AddOperator("*", 2, (direction)0, _mnozenie);
   mp.AddOperator("/", 2, (direction)0, _dzielenie);
   mp.AddOperator("s", 3, (direction)0, _pierwiastkowanie);  //________________4s2 pierwiastek 2-giego stopnia z 4,  9s3 pierwiastek 3-go stopnia z 9 itd.
   mp.AddOperator("^", 3, (direction)0, _potegowanie); //____________________2^2,  2^3 itd.
   mp.PreParse(exp);
   cout << "e - wyjscie LUB dowolny klawisz - wprowadz funkcje" << endl;
   key = getch();
   system("cls");
   }
   return EXIT_SUCCESS;
}

