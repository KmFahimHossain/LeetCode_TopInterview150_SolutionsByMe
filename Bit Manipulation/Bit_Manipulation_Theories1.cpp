#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

// Bit Manipulation Theories, part 1

string decimalToBinary( int dec)
{
    if (dec == 0) 
    {
        return "0";
    }

    string binary = "";
    int remainder = 0;
    while(dec != 0)
    {
        remainder = dec%2;
        dec /= 2;
        binary += to_string(remainder);
    }
    reverse(binary.begin() , binary.end());
    return binary;
}

int binaryToDecimal( string binary)
{
    int dec = 0;
    int powerOf2Value = 1;
    for(int i = binary.size() - 1; i >= 0; i--)
    {
        dec += powerOf2Value*(binary[i] - '0');
        powerOf2Value *= 2;
    }
    return dec;
}

void swapTwoNumbers(int& a, int& b)
{
    a = a^b;
    b = a^b;
    a = a^b;
}

int countBits(int a)
{
    int count = 0;
    while(a > 0)
    {
        if(a%2 == 1)
        {
            count++;
        }
        a /= 2;
    }
    return count;
}

int minBitFlip(int a, int b)
{
    int XOR = a^b;
    return countBits(XOR);
}

int bitwiseDivision(int dividend, int divisor)
{
    int sign = 1;
    if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
    {
        sign = -1;
    }
    dividend = abs(dividend);
    divisor = abs(divisor);

    int result = 0;
    while(dividend >= divisor)
    {
        int i = 0;
        while(divisor*(1<<(i+1)) <= dividend)
        {
            i++;
        }
        result += (1<<i);
        dividend -= divisor*(1<<i);
    }
    return sign*result;
}

int main()
{
    cout<<decimalToBinary(13)<<endl;
    cout<<binaryToDecimal("1101")<<endl;
    cout<<endl;

    cout<<(13 & 7)<<endl;
    cout<<(13 | 7)<<endl;
    cout<<(13 ^ 7)<<endl;
    cout<<(13 >> 2)<<endl;
    cout<<(13 << 2)<<endl;
    cout<<(~5)<<endl;
    cout<<(~-6)<<endl;
    cout<<(5^5)<<endl;
    cout<<(5^6)<<endl;

    int a = 14;
    int b = 17;
    cout<<a<<" "<<b<<endl;
    swapTwoNumbers(a,b);
    cout<<a<<" "<<b<<endl;

    cout<<countBits(13)<<endl;
    cout<<minBitFlip(10,7)<<endl;
    cout<<minBitFlip(3,3)<<endl;
    cout<<bitwiseDivision(22,3)<<endl;
    cout<<bitwiseDivision(-22,3)<<endl;
    cout<<"End"<<endl;
    return 0;
}
// Date : 24.04.2025
