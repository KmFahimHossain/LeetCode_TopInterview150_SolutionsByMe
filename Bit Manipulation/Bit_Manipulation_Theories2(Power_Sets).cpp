#include <iostream>
#include <vector>
using namespace std;

// Bit Manipulation Theories, part 2 (Power Sets)

vector<vector<int>> powerSets(char arr[], int n)
{
    vector<vector<int>> result;
    int numOfElementsInPowerSet = (1<<n);

    for(int i = 0; i < numOfElementsInPowerSet; i++)
    {
        vector<int> element;
        for(int j = 0; j < n; j++)
        {
            if(i&(1<<j))
            {
                element.push_back(arr[j]);
            }
        }
        result.push_back(element);
    }
    return result;
}

int main()
{
    char arr[] = {'a','b','c','d'};
    int n = sizeof(arr)/sizeof(char);
    vector<vector<int>> result = powerSets(arr, n);
    
    for(vector<int> a : result)
    {
        for(char b : a)
        {
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// Date : 24.04.2025