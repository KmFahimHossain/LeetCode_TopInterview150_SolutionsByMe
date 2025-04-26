#include <iostream>
#include <climits>
using namespace std;

// Problem statement - https://leetcode.com/problems/bitwise-and-of-numbers-range/description/

int rangeBitwiseAnd(int left, int right) 
{
    for (int i = 31; i > 0; i--) 
    {
        if (((left >> i) & 1) != ((right >> i) & 1)) 
        {
            return left & (INT_MAX << i);
        }
    }
    return left;
}

int main()
{
    int left = 5;
    int right = 7;
    cout<<rangeBitwiseAnd(left,right);
    return 0;
}
// Date: 26.4.25