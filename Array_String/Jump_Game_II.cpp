#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/jump-game-ii/description/

int solution(vector<int>& nums)
{
    int jumpCount = 0;
    int endPoint = nums.size()-1;

    for(int i = 0; i < endPoint; i++)
    {
        if(i+nums[i] >= endPoint)
        {
            jumpCount++;
            endPoint = i;
            i = -1;
        }
    }
    return jumpCount;
}

int main()
{
    vector<int> nums = {2,3,0,1,4};
    cout<<solution(nums);
    return 0;
}
// Date: 24.1.25