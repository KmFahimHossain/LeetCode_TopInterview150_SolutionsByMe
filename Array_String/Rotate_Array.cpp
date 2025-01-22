#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/rotate-array/description/

void solution(vector<int>& nums, int k)
{
    k = k % nums.size();
    if(k==0)
    {
        return;
    }
    int* temp = new int[k];
    //vector<int> temp(k); //This will also do

    int size = nums.size() - 1;
    for(int i = 0; i < k; i++)
    {
        temp[i] = nums[size - k + 1 + i];
    }

    for (int i = size; i >= k; i--)
    {
        nums[i] = nums[i-k];
    }

    for(int i = 0; i < k; i++)
    {
        nums[i] = temp[i];
    }
}

int main()
{ 
    vector<int> nums = {-1,2,3,4,5,6,7,0,1};
    int k = 3;

    solution(nums,k);
    for ( int i = 0; i < nums.size() ; i++)
    {
        cout<<nums[i]<<"  ";
    }
    return 0;
}
// Date: 22.1.25