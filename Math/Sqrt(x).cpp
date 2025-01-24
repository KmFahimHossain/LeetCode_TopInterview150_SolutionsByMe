#include <iostream>
using namespace std;

// Problem statement - https://leetcode.com/problems/sqrtx/description/

int solution(int x)
{
    int l = 0;
    int r = x;
    long long root;

    while(1)
    {
        root = (l+r)/2;

        if(root*root > x)
        {
            r = root-1;
        }

        else if(root*root < x)
        {
            l = root+1;
        }

        else
        {
            return root;
        }

        if((root+1)*(root+1) > x && (root)*(root) <= x )
        {
            break;
        }
    }
    return root;
}

int main()
{
    int x = 5000;
    cout<<solution(x)<<endl;
    return 0;
}
// Date: 24.1.25