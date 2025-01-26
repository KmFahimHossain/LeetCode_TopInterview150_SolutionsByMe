#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/candy/description/

int solution(vector<int>& ratings)
{
    int size = ratings.size();
    vector<int> candyCount(size, 1);

    for (int i = 1; i < size; i++) 
    {
        if (ratings[i] > ratings[i - 1] && candyCount[i] <= candyCount[i - 1]) 
        {
            candyCount[i] = candyCount[i - 1] + 1;
        }
    }

    for (int i = size - 2; i >= 0; i--) 
    {
        if (ratings[i] > ratings[i + 1] && candyCount[i] <= candyCount[i + 1]) 
        {
            candyCount[i] = candyCount[i + 1] + 1;
        }
    }

    int totalCandy = 0;
    for (int i = 0; i < size; i++) 
    {
        totalCandy = totalCandy + candyCount[i];
        //cout << candyCount[i] << endl;
    }
    return totalCandy;
}

int main()
{
    vector<int> ratings = {3,2,1,1,4,3,3};
    cout<<solution(ratings);
    return 0;
}
// Date: 26.1.25