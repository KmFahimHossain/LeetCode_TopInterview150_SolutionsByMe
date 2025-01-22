#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Problem statement - https://leetcode.com/problems/majority-element/description/

int solution(vector<int>& nums)
{
    unordered_map<int,int> hashmap;
    int size = nums.size();

    for(int i = 0; i < size ; i++)
    {
        hashmap[nums[i]]++;
    }

    int maxCount = 0;
    int maxValue = 0;
    for(auto pair : hashmap)
    {
        if(pair.second > maxCount )
        {
            maxCount = pair.second;
            maxValue = pair.first;
        }
    }
    return maxValue;
}

int main()
{ 
    vector<int> nums = {0,1,1,11,1,1,1,11,11,1,1,1,1,1,1,2,3,3,4,4,4,5,6,1,1,11,1,1,1,11,1};

    int element = solution(nums);
    cout<<element<<endl;
    
    return 0;
}
// Date: 22.1.25