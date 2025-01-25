#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem statement - https://leetcode.com/problems/h-index/description/

int solution(vector<int>& citations)
{
    sort(citations.begin(), citations.end());
    reverse(citations.begin(), citations.end());

    int size = citations.size();
    if(citations[size-1] >= size)
    {
        return size;
    }

    for(int i = 1; i<size; i++)
    {
        if(citations[i] < i+1)
        {
            return min(citations[i-1],i);
        }
    }
    return 0;
}

int main()
{
    vector<int> citations = {3,0,6,1,5};
    cout<<solution(citations);
    return 0;
}
// Date: 25.1.25