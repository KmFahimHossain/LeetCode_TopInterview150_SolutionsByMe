#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Problem statement - https://leetcode.com/problems/3sum/description/

vector<int> limitedSortedOccurrences(vector<int>& numbers) 
{
    vector<int> result;
    unordered_map<int, int> numOfOcc;
    int index = 0;
    int element = 0;
    while (index < numbers.size()) 
    {
        element = numbers[index];
        if (numOfOcc[element] < 3)
        {
            result.push_back(element);
            numOfOcc[element]++;
        } 
        index++;
    }
    return result;
}

vector<int> twoSum(vector<int>& numbers,int i, int target)
{
    int j = numbers.size() - 1;
    while(i < j)
    {
        if(numbers[i] + numbers[j] < target)
        {
            i++;
        }
        else if(numbers[i] + numbers[j] > target)
        {
            j--;
        }
        else
        {
            return {i, j};
        }
    }
    return {-1,-1};
}

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> result;
    vector<int> otherTwo;
    if(nums.size() > 50)
    {
        nums = limitedSortedOccurrences(nums);
    }

    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 2; i++)
    {
        if(nums[i] > 0)
        {
            break;
        }
        otherTwo = twoSum(nums, i+1, (-1)*nums[i]);
        while(otherTwo[0] != otherTwo[1])
        {
            result.push_back({nums[i] , nums[otherTwo[0]], nums[otherTwo[1]]});
            otherTwo = twoSum(nums, otherTwo[0] + 1, (-1)*nums[i]);
        }
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;
}

int main() 
{
    vector<int> nums = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<vector<int>> result = threeSum(nums);

    for(vector<int> results : result)
    {
        cout<<results[0]<<" "<<results[1]<<" "<<results[2]<<endl;
    }
    return 0;
}
// Date: 17.3.25