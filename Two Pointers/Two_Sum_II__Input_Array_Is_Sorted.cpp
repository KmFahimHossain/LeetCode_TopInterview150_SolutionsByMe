#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

vector<int> twoSum(vector<int>& numbers, int target)
{
    int i = 0;
    int j = numbers.size() - 1;
    while(1)
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
            return {i+1, j+1};
        }
    }
    return {-1,-1};
}

int main() 
{
    vector<int> numbers = {2,7,8,9,10,11,12,13,15};
    int target = 21;

    vector<int> result = twoSum(numbers, target);
    cout<<result[0]<<" "<<result[1];
    return 0;
}
// Date: 17.3.25