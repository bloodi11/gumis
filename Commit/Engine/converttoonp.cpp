#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<string> convertToONP(vector<string>& inputTokens, const int& size, vector<string>& strArray)
{
    stack<string> stack;
    vector<string> out;

    for (int i=0; i<size; i++)
    {
        string token= inputTokens[i];

        if (isOperator(token))
        {
            const string o1=token;

            if (!stack.empty())
            {
                string o2=stack.top();

                while ( isOperator(o2) &&
                        ( ( isAssociative( o1, LEFT_ASSOC ) &&  cmpPrecedence( o1, o2 ) == 0 ) ||
                        ( cmpPrecedence( o1, o2 ) < 0 ) ) )
                {
                    stack.pop();
                    out.push_back( o2 );

                    if ( !stack.empty())
                        o2 = stack.top();
                    else
                        break;
                }
            }

            stack.push( o1 );
        }
        else if(isFunction(token))
        {
            stack.push(token);
        }
        else if (token=="(")
        {
            stack.push(token);
        }
        else if (token == ")")
        {
            string topToken=stack.top();

            while (topToken!="(")
            {
                out.push_back(topToken);
                stack.pop();

                if (stack.empty()) break;
                topToken=stack.top();
            }
            if ( !stack.empty()) stack.pop();
        }

        else //czyli jest liczba
        {
           out.push_back(token);
        }
    }

    while (!stack.empty())
    {
        const string stackToken=stack.top();
        out.push_back(stackToken);
        stack.pop();
    }
    strArray.assign( out.begin(), out.end());
    return strArray;

}
