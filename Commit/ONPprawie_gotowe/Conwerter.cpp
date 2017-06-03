
#include "Conwerter.h"

void Conwerter::addOp(string name, int larg, int p, int kierunek)
{
	Oper op;
	op.name = name;
	op.piorytet = p;
	op.liczbarg = larg;
	op.kierunek = kierunek;
	ops.push_back(op);
	op_count++;
}

bool Conwerter::isLiczba(char c)
{
	if (c >= '1' && c <= '9') return true;
	else if (c == '0') return true;
	else if (c == '.') return true;
	else return false;
}

Conwerter::Conwerter()
{
	op_count = 0;
	error = 0;
	addOp("sin", 1, 3,1);
	addOp("cos", 1, 3,1);
	addOp("tg", 1, 3,1);
	addOp("ctg", 1, 3,1);
	addOp("sqrt", 1, 3,1);
	addOp("exp", 1, 3,1);
	addOp("+", 2, 1,0);
	addOp("-", 2, 1,0);
	addOp("*", 2, 2,0);
	addOp("/", 2, 2,0);
	addOp("^", 2, 4,1);


}

Conwerter::~Conwerter()
{
	while (!ops.empty())
	{
		ops.pop_back();
	}
}

string Conwerter::ChartoString(char c)
{
	stringstream ss;
	string s;
	ss << c;
	ss >> s;
	return s;
}

bool Conwerter::isZnak(char c)
{
	if (c >= 'a' && c <= 'z') return true;
	else return false;
}

bool Conwerter::ispodstawowy(char c)
{
	switch (c)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	{
		return true;
	}
	default:
		break;
	}
	return false;
}

bool Conwerter::isfun(string s)
{
	if (s == "sin" || s == "cos" || s == "tg" || s == "ctg" || s == "sqrt" || s == "exp")
	{
		return true;
	}
	else return false;
}

bool Conwerter::isOperator(string ch, Oper* op)
{
	Oper tmp = { "",0,0,0 };
	*op = tmp;
	bool IsOperatorl = false;
	for (int i = 0; i < op_count; i++)
	{
		if (ops[i].name == ch)
		{
			IsOperatorl = true;
			*op = ops[i];
			break;
		}
	}
	return IsOperatorl;
}


queue<string> Conwerter::ONP(string exp)
{
	queue<string> result;
	stack<string> stack;
	string s;
	int ln=0, pn=0;
	Oper wyk;
	if (isOperator(ChartoString(exp[0]), &wyk) == true || isOperator(ChartoString(exp[exp.size() - 1]), &wyk) == true)
	{
		error = 2;
		cout << "Nie mo¿e byc operator na poczatku lub na koncu" << endl;
		return result;
	}

	for (unsigned int i = 0; i < exp.size(); i++)
	{
		s = "";
		
		char ch = exp[i];
		if (ch == ' ')
		{
			continue;
		}
		else if (isLiczba(ch))
		{
			
			while (isLiczba(exp[i]))
			{
				s = s + ChartoString(exp[i]);
				i++;
			}
			i--;
			result.push(s);
		}
		else if (ch == '(')
		{
			stack.push(ChartoString(ch));
			ln++;
		}
		else if (ch == ')')
		{
			pn++;
			if (stack.empty())
			{
				cout << "Brakuje nawiasów" << endl;
				error = 1;
				return result;
			}
			else
			{
				while (stack.top() != "(")
				{
					result.push(stack.top());
					stack.pop();
				}
			}
			if (stack.top() != "(")
			{
				cout << "Brakuje nawiasów" << endl;
				error = 1;
				return result;
			}
			else
				stack.pop();
		}
		else
		{

			
			s += ChartoString(ch);
			if (ispodstawowy(ch))
			{
				if (ch=='-' && exp[i - 1] == '(')
				{
					result.push("0");
				}
				Oper cur;
				isOperator(s, &cur);

				Oper op;
				while (!stack.empty()&& isOperator(stack.top(), &op) == true)
				{
					if ((cur.kierunek == 0 && cur.piorytet <= op.piorytet) || (cur.kierunek == 1 && cur.piorytet < op.piorytet))
					{
						result.push(stack.top());
						stack.pop();
					}
					else
						break;
					if (stack.empty())
						break;
				}
				stack.push(s);
			}
			else
			{

				while (isZnak(exp[i + 1]))
				{
					s += ChartoString(exp[i + 1]);
					i++;
				}

				if (isfun(s))
				{
					Oper cur;
					isOperator(s, &cur);

					Oper op;
					while (!stack.empty() && isOperator(stack.top(), &op) == true)
					{
						if ((cur.kierunek == 0 && cur.piorytet <= op.piorytet) || (cur.kierunek == 1 && cur.piorytet < op.piorytet))
						{
							result.push(stack.top());
							stack.pop();
						}
						else
							break;
						if (stack.empty())
							break;
					}
					stack.push(s);
				}
				else if (s.size() == 1)
				{
					result.push(s);
				}
				else
				{
					cout << "Nie ma funkcji i nazwie: " << s << endl;
					error = 3;
					return result;
				}
			}
		}
	}


	while (!stack.empty())
	{
		result.push(stack.top());
		stack.pop();
	}

	if (ln != pn)
	{
		cout << "Brakuje nawiasów" << endl;
		error = 1;
	}


	return result;
}