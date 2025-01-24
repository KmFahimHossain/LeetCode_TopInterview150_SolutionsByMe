#include <iostream>
#include <climits>
using namespace std;

// Problem statement - https://leetcode.com/problems/powx-n/description/

double solution(double x, int n)
{
    if (x == 0) 
    {
        return 0;
    }

    if(n == 0)
    {
        return 1;
    }

    if (n == INT_MIN) 
    {
        if(x == 1 || x == -1)
        {
            return 1;
        }
        return 0;
    }

    if (n < 0) 
    {
        x = 1 / x;
        n = n * -1;
    }

    double result = 1.0;
    while (n > 0) 
    {
        if (n % 2 == 0) 
        {
            x = x * x;
            n = n / 2;
        }
        result = result * x;
        n--;
    }
    return result;
}

int main()
{
    double x = 0.999999;
    int n = 100000;
    cout<<solution(x,n)<<endl;
    return 0;
}
// Date: 24.1.25