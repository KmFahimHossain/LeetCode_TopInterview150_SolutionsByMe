#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Bit Manipulation Theories, part 3 (Single Number)

//Single Number, all number twice except one
int singleNumber(vector<int>nums)
{
    int XOR = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        XOR = XOR^nums[i];
    }
    return XOR;
}

//Single Number, all number thrice except one
int singleNumber2(vector<int>nums)
{
    vector<int> bits(31,0);
    for(int i = 0; i < 31; i++)
    {
        for(int j = 0; j < nums.size(); j++)
        {
            if(nums[j] & (1<<i))
            {
                bits[i]++;
            }
        }
    }

    int result = 0;
    for(int i = 0; i < 31; i++)
    {
        if(bits[i]%3 != 0)
        {
            result = result | (1<<i);
        }
    }
    return result;
}

//Single Number, all number thrice except one
int withoutBit(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size();)
    {
        if(nums[i] == nums[i+1])
        {
            i += 3;
        }
        else
        {
            return nums[i];
        }
    }
    return nums[nums.size() - 1];
}

//Single Number, all number thrice except one, Extreme optimization

// Let's assume we have two buckets - ones and twos.
// Now, for every seperate bit that's encountered,

// if the bit was encountered for the first time , then -
// ones = 0
// twos = 0
// so after the operations, 
// ones = 1
// twos = 0

// if the bit was encountered once before, then - 
// ones = 1
// twos = 0
// so, after the operations,
// ones = 0
// twos = 1

// if the number was encountered twice before, then - 
// ones = 0
// twos = 1
// so, after the operations,
// ones = 0
// twos = 0

// after all the iterations, ones will only contain the bits of the single number.

int singleNumber3(vector<int> nums)
{
    int ones = 0, twos = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        ones = (nums[i]^ones) & ~twos;
        twos = (nums[i]^twos) & ~ones;
    }
    return ones;
}

// All number twice except two distinct numbers occuring once
vector<int> singleNumber4 (vector<int> nums)
{
    int XOR = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        XOR = XOR^nums[i];
    }
    // XOR now contains the XOR of that two distinct numbers
    int differentBit = XOR ^ (XOR & (XOR - 1));

    int bucket1 = 0, bucket2 = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] & differentBit)
        {
            bucket1 = bucket1^nums[i];
        }
        else
        {
            bucket2 = bucket2^nums[i];
        }
    }
    return{bucket1,bucket2};
}

int main()
{
    vector<int> nums = {1,2,3,2,3,4,4,1,5,5,14,6,6};
    cout<<singleNumber(nums)<<endl;
    vector<int> nums2 = {1,1,2,2,3,2,3,4,4,3,4,1,17,12,12,12};
    cout<<singleNumber2(nums2)<<endl;
    cout<<withoutBit(nums2)<<endl;
    cout<<singleNumber3(nums2)<<endl;
    vector<int> nums3 = {2,4,2,14,8,7,7,8};
    vector<int> result = singleNumber4(nums3);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}
// Date : 24.04.2025