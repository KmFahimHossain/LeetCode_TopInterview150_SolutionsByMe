#include <iostream>
using namespace std;

// Problem statement - https://leetcode.com/problems/reverse-bits/description/

uint32_t reverseBits(uint32_t n)
{
    for(int i = 0; i < 16; i++)
    {
        if( ((n>>i)&1) != ((n>>(31-i))&1))
        {
            n = n^(1<<i);
            n = n^(1<<(31-i));
        }
    }
    return n;
}

int main() 
{
    uint32_t n = 7; //00000000 00000000 00000000 00000111
    cout<<reverseBits(n); //1110 0000 0000 0000 0000 0000 0000 0000 = 3758096384
    return 0;
}
// Date: 26.4.25