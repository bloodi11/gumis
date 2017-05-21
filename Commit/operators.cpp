
#include <map>
#include <string>
#include <iterator>
using namespace std;

const int LEFT_ASSOC=0;
const int RIGHT_ASSOC=1;

// Map the different operators: +, -, *, / etc
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
