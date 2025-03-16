#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/is-subsequence/description/

bool isSubsequence(string s, string t)
{
    int size1 = s.size();
    int size2 = t.size();
    for(int i = 0, j = 0; i < size1 && j < size2; )
    {
        if(s[i] == t[j])
        {
            i++;
            j++;
            if(i==size1)
            {
                return true;
            }
        }
        else
        {
            j++;
            if(j==size2)
            {
                return false;
            }
        }
    }
    return !s.size();
}

int main() 
{
    string s = "";
    string t = "acdjbf";
    cout<<isSubsequence(s,t);
    return 0;
}
// Date: 16.3.25