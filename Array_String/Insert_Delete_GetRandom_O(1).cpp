#include <iostream>
#include <vector>
#include <unordered_map>
#include <time.h>
using namespace std;

// Problem statement - https://leetcode.com/problems/insert-delete-getrandom-o1/description/

class RandomizedSet 
{
    private:
    vector<int> elements;
    unordered_map<int, int> hashmap;
    int size;

    public:
    RandomizedSet() 
    { 
        size = 0;
        srand(time(0)); 
    }

    bool insert(int val) 
    {
        if (hashmap.find(val) == hashmap.end()) 
        {
            elements.push_back(val);
            hashmap[val] = size;
            size++;
            return true;
        }
        return false;
    }

    bool remove(int val) 
    {
        if (hashmap.find(val) != hashmap.end()) 
        {
            int index = hashmap[val];
            elements[index] = elements[size - 1];
            hashmap[elements[index]] = index;
            elements.pop_back();
            size--;
            hashmap.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() 
    {
        if(size==1)
        {
            return elements[0];
        }
        int random = rand() % (elements.size());
        return elements[random];
    }
};

int main()
{
    RandomizedSet obj;
    bool param_1 = obj.insert(0);
    bool param_2 = obj.insert(1);
    bool param_3 = obj.remove(3);
    int param_4 = obj.getRandom();
    bool param_5 = obj.insert(2);
    bool param_6 = obj.remove(1);
    int param_7 = obj.getRandom();

    cout<<param_1<<" "<<param_2<<" "<<param_3<<" "<<param_4<<endl;
    cout<<param_5<<" "<<param_6<<" "<<param_7<<endl;

    return 0;
}
// Date: 26.1.25