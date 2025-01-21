#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

int solution(vector<int>& nums)
{
    int size = nums.size();

    if (size == 1 || size == 2) 
    {
        return size;
    }

    for (int i = 1; i < size-1; i++)
    {
        while(nums[i] == nums[i-1] && nums[i] == nums[i+1])
        {
            for(int j = i+1; j<size; j++)
            {
                nums[j-1] = nums[j];
            }
            size--;

            if(i == size-1)
            {
                return size;
            }
        }
    }
    return size;
}

int main()
{ 
    vector<int> nums = {0,0,0,1,2,2,3,3,4,5,5,5,5,5,6,7,8,8,8};

    int count = solution(nums);
    cout<<count<<endl;

    for ( int i = 0; i < count ; i++)
    {
        cout<<nums[i]<<endl;
    }
    return 0;
}
// Date: 21.1.25