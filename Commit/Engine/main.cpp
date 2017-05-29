#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <iterator>
#include <map>
#include <operators.cpp>
#include <converttoonp.cpp>
#include <tokenizer.cpp>
#include <functions.cpp>
#include <functions2.cpp>
#include <rpntovalue.cpp>

using namespace std;
//do dokonczenia
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
