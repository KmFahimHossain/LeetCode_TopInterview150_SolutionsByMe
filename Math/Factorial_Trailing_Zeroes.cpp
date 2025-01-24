#include <iostream>
using namespace std;

// Problem statement - https://leetcode.com/problems/factorial-trailing-zeroes/description/

int solution(int n)
{
    int zeroCount = 0;
    for(int i = 1; i<=n; i++)
    {
        int x = i;
        while(x%5 == 0)
        {
            zeroCount++;
            x = x/5;
        }
    }
    return zeroCount;
}

int main()
{ 
    int n =26;
    cout<<solution(n);
    return 0;
}
// Date: 24.1.25