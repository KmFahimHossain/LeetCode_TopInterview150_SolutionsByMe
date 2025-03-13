#include <iostream>
#include <stack>
using namespace std;

// Problem statement - https://leetcode.com/problems/valid-parentheses/description/

bool isValid(string s)
{
    stack<char> st;
    for(char ch : s)
    {
        if(ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }

        else if(!st.empty())
        {
            if(ch == ')' && st.top() == '(' ||
               ch == '}' && st.top() == '{' ||
               ch == ']' && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return st.empty();
}

int main()
{
    string s = ")";
    cout<< isValid(s);
    return 0;
}
// Date: 13.3.25
