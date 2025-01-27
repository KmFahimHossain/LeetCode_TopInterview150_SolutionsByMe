#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem statement - https://leetcode.com/problems/trapping-rain-water/description/

int solution(vector<int>& height)
{
    int waterCount = 0;
    int size = height.size();
    vector<int> leftMax(size, 0);
    vector<int> rightMax(size, 0);

    leftMax[0] = height[0];
    for (int i = 1; i < size; i++) 
    {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    rightMax[size - 1] = height[size-1];
    for (int i = size - 2; i >= 0; i--) 
    {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int amount = 0;
    for(int i = 1; i < size - 1; i++)
    {
        amount = min(leftMax[i],rightMax[i]) - height[i];
        if(amount > 0)
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