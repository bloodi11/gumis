#include<string>
#include<vector>

using namespace std;

bool isFunction(const string& token, const int&size)
{
    for (int i=0; i<size; i++)
    {
        if(token=="t" || token=="s" || token=="c" || token=="p")
            return true;
    }
}

