#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem statement - https://leetcode.com/problems/trapping-rain-water/description/

int solution(vector<int>& height)
{
    int waterCount = 0;
    int size = height.size();
    if (size < 3) 
    {
        return waterCount;
    }

    int start = 0;
    while (height[start] <= height[start + 1]) 
    {
        start++;
        if (start == size - 2) 
        {
            return waterCount;
        }
    }

    int amount = 0;
    int leftMax = -1;
    int rightMaxIndex = max_element(height.begin(), height.end()) - height.begin();
    int rightMax = height[rightMaxIndex];
    for (int i = start + 1; i < size - 1; i++) 
    {
        if (height[i - 1] > leftMax) 
        {
            leftMax = height[i - 1];
        }

        if (i >= rightMaxIndex) 
        {
            rightMaxIndex = max_element(height.begin() + i + 1, height.end()) - height.begin();
            rightMax = height[rightMaxIndex];
        }

        amount = min(leftMax, rightMax) - height[i];
        if (amount > 0) 
        {
            waterCount = waterCount + amount;
        }
    }
    return waterCount;
}

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<solution(height);
    return 0;
}
// Date: 27.1.25