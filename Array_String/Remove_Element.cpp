#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/remove-element/description/

int solution(vector<int>& nums, int val)
{
    if(nums.size() == 0)
    {
        return 0;
    }

    int count = 0;
    for ( int i = 0; i < nums.size() ; i++)
    {
        if(nums[i] != val)
        {
            count++;
        }
    }

    for(int i = 0, j = nums.size() - 1; i < count; )
    {
        if(nums[i] != val)
        {
            i++;
        }

        else if(nums[i] == val && nums[j] != val)
        {
            nums[i] = nums[j];
            i++;
            j--;
        }

        else if(nums[j] == val)
        {
            j--;
        }
    }
    return count;
}

int main()
{
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;

    int count = solution(nums, val);
    cout<<count<<endl;

    for ( int i = 0; i < count ; i++)
    {
        cout<<nums[i]<<endl;
    }

    return 0;
}

// Date: 21.1.25