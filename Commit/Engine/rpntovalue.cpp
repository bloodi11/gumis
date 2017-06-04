#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <math.h>

using namespace std;

double RPNtoDouble( std::vector<std::string> tokens )        
{        
    std::stack<std::string> st;       
 
    // For each token        
    for ( int i = 0; i < (int) tokens.size(); ++i )        
    {       
        const std::string token = tokens[ i ];      

        if ( !isOperator(token) )        
        {        
            st.push(token);        
        }        
        else       
        {  
            double result =  0.0;    
            const std::string val2 = st.top();      
            st.pop();      
            const double d2 = strtod( val2.c_str(), NULL );        
 
            if ( !st.empty() )  
            {  
                const std::string val1 = st.top();      
                st.pop();      
                const double d1 = strtod( val1.c_str(), NULL );        
                result = token == "+" ? d1 + d2 :        
                         token == "-" ? d1 - d2 :        
                         token == "*" ? d1 * d2 :        
                                        d1 / d2;        
            }  
            else 
            {  
                if ( token == "-" )  
                    result = d2 * -1;  
                else  
                    result = d2;  
            }  
            
            std::ostringstream s;      
            s << result;      
            st.push( s.str() );        
        }        
    }                
 
    return strtod( st.top().c_str(), NULL );      
}        
