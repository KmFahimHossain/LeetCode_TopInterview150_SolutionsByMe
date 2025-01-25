#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Problem statement - https://leetcode.com/problems/two-sum/description/

vector<int> solution(vector<int>& nums, int target)
{
    unordered_map<int, int> hashmap;
    int size = nums.size();
    for (int i = 1; i < size; i++) 
    {
        int complement = target - nums[i];
        if (hashmap[complement] != 0) // Hashmap will return 0 for keys that do not exist
        {
            return {hashmap[complement],i};
        }
        else if (nums[0] == complement) 
        {
            return {0, i};
        }
        hashmap[nums[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> nums = {2,7,8,11,15};
    int target = 18;

    vector<int> solutionArray = solution(nums,target);
    for ( int i = 0; i < solutionArray.size() ; i++)
    {
        cout<<solutionArray[i]<<" ";
    }
    return 0;
}
// Date: 25.1.25