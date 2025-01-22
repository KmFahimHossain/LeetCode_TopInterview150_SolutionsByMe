#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

int solution(vector<int>& prices)
{
    int tempMax = 0;

    int size = prices.size() - 1;
    for (int i = 0; i < size; i++) 
    {
        while (prices[i + 1] < prices[i]) 
        {
            i++;
            if (i == size) 
            {
                return tempMax;
            }
        }

        int nextLargest = prices[i + 1];
        int endPoint;

        for (int j = i + 1; j <= size; j++) 
        {
            if (prices[j] >= nextLargest) 
            {
                nextLargest = prices[j];
                endPoint = j;
            }
        }

        while (i != endPoint) 
        {
            if (nextLargest - prices[i] > tempMax) 
            {
                tempMax = nextLargest - prices[i];
            }
            i++;
        }
    }
    
    return tempMax;
}

int main()
{ 
    vector<int> prices = {7,1,5,3,6,4};
    cout<<solution(prices);
    return 0;
}
// Date: 22.1.25