#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/product-of-array-except-self/description/

vector<int> solution(vector<int>& nums)
{
    int product = 1;
    int productIfZero = 0;

    int size = nums.size();
    for(int i = 0; i<size; i++)
    {
        if(productIfZero == 0 && nums[i] == 0 )
        {
            productIfZero = 1;
        }
        else
        {
            product *= nums[i];
        }
    }

    if(productIfZero >= 1)
    {
        productIfZero = product;
        product = 0;
    }

    for(int i = 0; i<size; i++)
    {
        if(nums[i] == 0)
        {
            nums[i] = productIfZero;
        }
        else
        {
            nums[i] = product/nums[i];
        }
    }
    return nums;
}

int main()
{
    vector<int> nums = {4,13,1,5,2,3,5};
    //vector<int> nums = {4,-3,0,5,2,3,5};
    vector<int> nums2 = solution(nums);

    for ( int i = 0; i < nums2.size() ; i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}
// Date: 25.1.25