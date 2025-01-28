#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Problem statement - https://leetcode.com/problems/roman-to-integer/description/

int solution(string s)
{
    int value = 0;
    unordered_map<char,int> romanValue = 
    {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int size = s.size();
    for(int i  = 0; i<size-1; i++)
    {
        if(romanValue[s[i+1]] > romanValue[s[i]])
        {
            value -= romanValue[s[i]];
        }
        else
        {
            value += romanValue[s[i]];
        }
    }
    value += romanValue[s[size-1]];
    return value;
}

int main()
{
    string s = "MCMXCIV";
    cout<<solution(s); // 1994
    return 0;
}
// Date: 28.1.25