#include <vector>
#include <string>

using namespace std;
vector <string> expression_tokenizer(const string& exp)
{
    vector <string> tokens;
    string str="";

    for (int i=0; i<(int)exp.length(); ++i)
    {
        const string token(1, exp[i]);

        if (isOperator(token) || isParenthesis(token) || isFunction(token))
        {
            if (!str.empty())
            {
               tokens.push_back(str);
            }
            str = "";
            tokens.push_back(token);
        }
        else
        {
            if (!token.empty() && token != " ")
            {
                str.append(token);
            }
            else
            {
                if (str!="")
                {
                    tokens.push_back(str);
                    str="";
                }
            }
        }
    }

    return tokens;
}
