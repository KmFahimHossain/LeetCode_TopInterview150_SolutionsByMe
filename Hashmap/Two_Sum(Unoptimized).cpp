#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/two-sum/description/

vector<int> solution(vector<int>& nums, int target)
{
    int size = nums.size();
    for(int i = 0; i<size; i++)
    {
        for(int j = i+1; j<size; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                return {i,j};
            }
        }
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
