#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

bool isSin(const string& token, const int&size);
bool isCos(const string& token, const int&size);
bool isTg(const string& token, const int&size);
bool isCtg(const string& token, const int&size);
bool isPow(const string& token, const int&size);
bool isSqrt(const string& token, const int&size);

vector <string> func;
string sin, cos, tg, ctg, pow, sqrt;
