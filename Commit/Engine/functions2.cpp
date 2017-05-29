#include <iostream>
#include <string>

using namespace std;

string sin, cos, tg, ctg, pow, sqrt;

bool isSin(const string& exp)
{
   size_t position=exp.find(sin);
   if(position==string::npos)
   {
       return false;
   }
}

bool isCos(const string& exp)
{
    size_t position=exp.find(cos);
    if(position==string::npos)
    {
        return false;
    }
}

bool isTg(const string& exp)
{
    size_t position=exp.find(tg);
    if(position==string::npos)
    {
        return false;
    }
}

bool isCtg(const string& exp)
{
    size_t position=exp.find(ctg);
    if(position==string::npos)
    {
        return false;
    }
}

bool isPow(const string& exp)
{
    size_t position=exp.find(pow);
    if(position==string::npos)
    {
        return false;
    }
}

bool isSqrt(const string& exp)
{
    size_t position=exp.find(sqrt);
    if(position==string::npos)
    {
        return false;
    }
}
