#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/gas-station/description/

int solution(vector<int>& gas, vector<int>& cost)
{
    int size = gas.size();
    if(size == 1)
    {
        if(gas[0] >= cost[0])
        {
            return 0;
        }
        return -1;
    }

    for(int i = 0; i<size; i++)
    {
        while(gas[i] <= cost[i])
        {
            i++;
            if(i == size)
            {
                return -1;
            }
        }

        int position = i;
        int tank = gas[i];
        while(tank - cost[position] >= 0)
        {
            tank = tank - cost[position] + gas[(position+1)%size];
            position = (position+1)%size;
            if(position == i)
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout<<solution(gas, cost);
    return 0;
}
// Date: 26.1.25