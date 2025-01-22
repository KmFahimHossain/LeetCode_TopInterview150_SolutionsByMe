#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/majority-element/description/

int solution(vector<int>& nums)
{
    int size = nums.size();
    int countNeeded = size/2;
    int count = 0;

    for(int i = 0; i < countNeeded ; i++)
    {
        count = 1;
        if(count > countNeeded)
        {
            return nums[i];
        }

        for (int j = i+1; j<size; j++)
        {
            if(nums[i] == nums[j])
            {
                count++;
                if(count > countNeeded)
                {
                    return nums[i];
                }
            }
        }
    }
    return nums[0];
}

int main()
{ 
    vector<int> nums = {0,1,1,11,1,1,1,11,11,1,1,1,1,1,1,2,3,3,4,4,4,5,6,1,1,11,1,1,1,11,1};

    int element = solution(nums);
    cout<<element<<endl;
    
    return 0;
}
// Date: 22.1.25