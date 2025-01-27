#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/longest-common-prefix/description/

string solution(vector<string>& strs)
{
    int count = 0;
    int size1 = strs.size();
    if(size1 == 1)
    {
        return strs[0];
    }

    int size2 = strs[0].size();
    if(size2 == 0)
    {
        return "";
    }

    int i =  0;
    while(strs[i][count] == strs[i+1][count])
    {
        i++;
        if(i==size1-1)
        {
            i=0;
            count++;
            if(count == size2)
            {
                break;
            }
        }
    }
    return strs[0].substr(0,count);
}

int main()
{
    vector<string>strs = {"flower","flow","flight","flMessi"};
    cout<<solution(strs);
    return 0;
}
// Date: 27.1.25