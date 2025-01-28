#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Problem statement - https://leetcode.com/problems/integer-to-roman/description/

string solution(int num)
{
    vector<int> value = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string> symbol = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    string roman = "";
    int i = 0;
    while(num > 0)
    {
        if(num >= value[i])
        {
            num -= value[i];
            roman += symbol[i];
        }
        else
        {
            i++;
        }
    }
    return roman;
}

int main()
{
    int num = 3749;
    cout<<solution(num);
    return 0;
}
// Date: 29.1.25