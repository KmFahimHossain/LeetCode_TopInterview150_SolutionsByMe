#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Problem statement - https://leetcode.com/problems/add-binary/description/

string addBinary(string a, string b) 
{
    string result = "";
    int sum = 0, carry = 0;
    for(int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j-- )
    {
        if(i >= 0 && j >= 0)
        {
            sum = a[i] - '0' + b[j] - '0' + carry;
        }
        else if(i < 0)
        {
            sum = b[j] - '0' + carry;
        }
        else if(j < 0)
        {
            sum = a[i] - '0' + carry;
        }

        if(sum == 0)
        {
            result += '0';
            carry = 0;
        }
        else if(sum == 1)
        {
            result += '1';
            carry = 0;
        }
        else if(sum == 2)
        {
            result += '0';
            carry = 1;
        }
        else if(sum == 3)
        {
            result += '1';
            carry = 1;
        }
    }

    if(carry == 1)
    {
        result += '1';
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() 
{
    string a = "1010";
    string b = "1011";
    cout<<addBinary(a,b);
    return 0;
}
// Date: 24.4.25