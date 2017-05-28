#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <iterator>
#include <map>

using namespace std;

const int LEFT_ASSOC=0;
const int RIGHT_ASSOC=1;

typedef map< string, pair< int,int > > OpMap;
typedef vector<string>::const_iterator cv_iter;
typedef string::iterator s_iter;

const OpMap::value_type assocs[]=
    {
        OpMap::value_type( "+", make_pair<int,int>(0, LEFT_ASSOC)),
        OpMap::value_type( "-", make_pair<int,int>(0, LEFT_ASSOC)),
        OpMap::value_type( "*", make_pair<int,int>(5, LEFT_ASSOC)),
        OpMap::value_type( "/", make_pair<int,int>(5, LEFT_ASSOC))
    };

const OpMap opmap(assocs, assocs+sizeof(assocs)/sizeof(assocs[0]));


bool isAssociative(const string& token, const int& type)
{
    const pair<int,int>p=opmap.find(token)->second;
    return p.second==type;
}

int cmpPrecedence (const string& token1, const string& token2)
{
    const pair<int,int> p1=opmap.find(token1)->second;
    const pair<int,int> p2=opmap.find(token2)->second;

    return p1.first -p2.first;
}

bool isOperator (const string& token)
{
    if(token=="+" || token=="-" || token=="/" || token=="*")
        return true;
}

bool isParenthesis (const string& token)
{
    if(token=="(" || token==")")
        return true;
}

bool isFunction(const string& token)
{
    if(atoi(token.c_str())<=9 && atoi(token.c_str())>=0)
        return true;
}

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

vector<string> convertToONP(vector<string>& inputTokens, const int& size, vector<string>& strArray)
{
    stack<string> stack;
    vector<string> out;

    for (int i=0; i<size; i++)
    {
        string token=inputTokens[i];

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


template<typename T, typename InputIterator>
void Print( const string& message,
             const InputIterator& itbegin,
             const InputIterator& itend,
             const string& delimiter)

{
    cout<<message<<endl;
    copy(itbegin, itend, ostream_iterator<T>(cout, delimiter.c_str()));
    cout<<endl;
}

int main()
{
    string in;
    cout<<"Podaj wyra"<<char(190)<<"enie."<<endl;
    Print<char, s_iter>("Wprowadzono: ", in.begin(), in.end(), "");
    vector<string> tokens=expression_tokenizer(in);
    vector<string> rpn=convertToONP(tokens, tokens.size(), rpn);
    Print<string, cv_iter>("Zapis ONP:  ", rpn.begin(), rpn.end(), " ");

    return 0;
}
