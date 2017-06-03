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


class Conwerter
{
private:
	struct Oper
	{
		string name;
		int liczbarg;
		int piorytet;
		int kierunek;//0-lewo, 1- prawo
	};
	vector<Oper> ops;
	int op_count;
	int error;
	bool innezmienne;

public:
	Conwerter();
	~Conwerter();
	void addOp(string name, int larg, int p, int kierunek);
	bool licz() { return innezmienne; }
	bool isLiczba(char c);
	string ChartoString(char c);
	bool isZnak(char c);
	bool ispodstawowy(char c);
	bool isfun(string s);
	vector<string> ONP(string exp);
	bool isOperator(string ch, Oper* op);
	int blad() { return error; }
	double stringTodouble(string s);

	double Parser(vector<string> result, double x, double y);

};
