#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

int solution(vector<int>& prices)
{
    int size = prices.size() - 1;
    if(size == 0)
    {
        return 0;
    }

    int profit = 0;
    for (int i = 0; i <= size; i++) 
    {
        if(i==0)
        {
            if(prices[i] <= prices[i+1])
            {
                profit -= prices[i];
            }
        }

        else if(i==size)
        {
            if(i==size && prices[i] >= prices[i-1])
            {
                profit += prices[i];
            }
            return profit;
        }

        else if(prices[i] < prices[i-1] && prices[i] <= prices[i+1])
        {
            profit -= prices[i];
        }

        else if(prices[i] >= prices[i-1] && prices[i] > prices[i+1])
        {
            profit += prices[i];
        }
    }
    return profit;
}

int main()
{ 
    vector<int> prices = {7,1,5,3,6,4};
    cout<<solution(prices);
    return 0;
}
// Date: 23.1.25