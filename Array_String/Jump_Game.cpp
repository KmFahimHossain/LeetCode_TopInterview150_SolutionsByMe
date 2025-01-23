#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/jump-game/description/

bool solution(vector<int>& nums)
{
    int size = nums.size();
    if(size==1)
    {
        return true;
    }

    int max = nums[0];
    int maxIndex = 0;
    for(int i = 0; i < size; i++)
    {
        if(nums[i]+i >= max+maxIndex && nums[i] != 0)
        {
            max = nums[i];
            maxIndex = i;

            if(max+maxIndex >= size-1)
            {
                return true;
            }
        }

        else if(nums[i] == 0)
        {
            while( i<size-1  && nums[i+1] == 0)
            {
                i++;
            }

            if(maxIndex + max <= i)
            {
                return false;
            }

            else
            {
                for(int j = 0; j<max; j++)
                {
                    if(i+j > size)
                    {
                        return true;
                    }

                    if(nums[i+j]+i+j > max+maxIndex && nums[i+j] != 0)
                    {
                        max = nums[i+j];
                        maxIndex = i+j;
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    vector<int> nums = {5,9,3,2,1,0,2,3,3,1,0,0};
    cout<<solution(nums);
    return 0;
}
// Date: 23.1.25