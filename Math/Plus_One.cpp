#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/plus-one/description/

vector<int> solution(vector<int>& digits)
{
    int size = digits.size() -1;
    while(size>= 0 && digits[size] == 9)
    {
        digits[size] = 0;
        size--;
        if(size==-1)
        {
            vector<int> newDigits(digits.size() + 1,0);
            newDigits[0] =1;
            return newDigits;
        }
    }
    digits[size]++;
    return digits;
}

int main()
{
    vector<int> digits = {1,2,2,0,2,0,8,8,9};
    //vector<int> digits = {9,9};

    vector<int> digits2 = solution(digits);
    for ( int i = 0; i < digits2.size(); i++)
    {
        cout<<digits2[i]<<endl;
    }
    return 0;
}
// Date: 24.1.25
