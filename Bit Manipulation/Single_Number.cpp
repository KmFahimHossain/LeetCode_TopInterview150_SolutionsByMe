#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/single-number/description/

int singleNumber(vector<int>& nums) 
{
    int XOR = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        XOR = XOR^nums[i];
    }
    return XOR;
}

int main()
{
    vector<int> nums = {4,1,2,1,2};
    cout<<singleNumber(nums);
    return 0;
}
// Date: 26.4.25