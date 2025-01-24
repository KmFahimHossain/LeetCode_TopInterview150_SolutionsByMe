#include <iostream>
using namespace std;

// Problem statement - https://leetcode.com/problems/palindrome-number/description/

bool solution(int x)
{
    if (x < 0) 
    {
        return false;
    }

    string digits = to_string(x);
    for (int l = 0, r = digits.size() - 1; l < r; l++, r--) 
    {
        if (digits[l] != digits[r]) 
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int x = 115010511;
    cout<<solution(x)<<endl;
    return 0;
}
// Date: 24.1.25