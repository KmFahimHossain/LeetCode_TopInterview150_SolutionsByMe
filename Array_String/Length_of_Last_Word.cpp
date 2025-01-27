#include <iostream>
using namespace std;

// Problem statement - https://leetcode.com/problems/length-of-last-word/description/

int solution(string s)
{
    int i = s.size()-1;
    while(s[i] == ' ')
    {
        i--;
        if(i==-1)
        {
            return 0;
        }
    }
    int first = i;

    while(s[i] != ' ')
    {
        i--;
        if(i==-1)
        {
            return first+1;
        }
    }
    int second = i;

    return first - second;
}

int main()
{
    string s = " messi is gOAT   ";
    cout<<solution(s);
    return 0;
}
// Date: 27.1.25