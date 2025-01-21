#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

int solution(vector<int>& nums)
{
    if(nums.size() == 1)
    {
        return 1;
    }

    int count = 1;
    for(int i = 0; i < nums.size() - 1; i++)
    {
        int j = i+1;

        while(!(nums[i] < nums[j]))
        {
            j++;
            if( j == nums.size())
            {
                return count;
            }
        }

        int temp = nums[i+1];
        nums[i+1] = nums[j];
        nums[j] = temp;
        count++;
    }

    return count;
}

int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4,4,6,8,9};
    
    int count = solution(nums);
    cout<<count<<endl;

    for ( int i = 0; i < count ; i++)
    {
        cout<<nums[i]<<endl;
    }

    return 0;
}

// Date: 21.1.25