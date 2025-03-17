#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/container-with-most-water/description/

int maxArea(vector<int>& height)
{
    int i = 0;
    int j = height.size() - 1;
    int water = 0;
    int maxWater = 0;
    while(i<j)
    {
        water = min(height[i], height[j])*(j-i);
        if(water > maxWater)
        {
            maxWater = water;
        }
        
        if(height[i] <= height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return maxWater;
}

int main() 
{
    vector<int> height = {1,3,2,5,25,24,5};
    cout<<maxArea(height);
    return 0;
}
// Date: 17.3.25