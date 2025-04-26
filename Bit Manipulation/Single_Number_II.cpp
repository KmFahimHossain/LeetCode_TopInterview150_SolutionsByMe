#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/single-number-ii/description/

int singleNumber(vector<int>& nums) 
{
    int ones = 0, twos = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        ones = (nums[i]^ones) & ~twos;
        twos = (nums[i]^twos) & ~ones;
    }
    return ones;
}

int main()
{
    vector<int> nums = {0,1,0,1,0,1,99};
    cout<<singleNumber(nums);
    return 0;
}
// Date: 26.4.25