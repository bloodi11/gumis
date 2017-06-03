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

public:
	Conwerter();
	~Conwerter();
	void addOp(string name, int larg, int p, int kierunek);
	bool isLiczba(char c);
	string ChartoString(char c);
	bool isZnak(char c);
	bool ispodstawowy(char c);
	bool isfun(string s);
	queue<string> ONP(string exp);
	bool isOperator(string ch, Oper* op);
	int blad() { return error; }

};
