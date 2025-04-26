#include <iostream>
using namespace std;

// Problem statement - https://leetcode.com/problems/number-of-1-bits/description/

int hammingWeight(int n) 
{
    int count  = 0;
    for(int i = 0; i < 31; i++)
    {
        if((n>>i)&1)
        {
            count++;
        }
    }
    return count;
}

int main() 
{
    int n = 11;
    cout<<hammingWeight(n);
    return 0;
}
// Date: 26.4.25