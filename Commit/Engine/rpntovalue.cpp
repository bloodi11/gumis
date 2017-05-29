#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <math.h>

using namespace std;

//do dokonczenia!!
string CalcValue(vector<string>& tokens)
{
    stack<string> st;
    for (int i=0; i<(int)tokens.size(); ++i)
        {
            const string token=tokens[i];

            if (!isOperator(token) && !isFunction(token))
            {
                st.push(token);
            }
            else
            {
                if(isSin(token));
                if(isCos(token));
                if(isTg(token));
                if(isCtg(token));
                if(isPow(token));
                if(isSqrt(token));
                if(isOperator(token));
            }

        }
}
