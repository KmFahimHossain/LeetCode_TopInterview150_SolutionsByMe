#include <iostream>
using namespace std;

// Problem statement - https://leetcode.com/problems/valid-palindrome/description/

bool solution(string s)
{
    string newString;
    int size = s.size();
    for(int i = 0; i<size; i++)
    {
        if(isalnum(s[i]))
        {
            newString += tolower(s[i]);
        }
    }

    size = newString.size();
    for(int i = 0, j = size - 1; i < j; i++,j--)
    {
        if(newString[i] != newString[j])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    cout<<solution(s);
    return 0;
}
// Date: 27.1.25
