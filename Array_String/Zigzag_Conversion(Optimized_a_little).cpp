#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/zigzag-conversion/description/

string convert(string s, int numRows)
{
    if(numRows == 1)
    {
        return s;
    }

    vector<vector<char>> record(numRows);

    int size = s.size();
    int index = 0, i = 0,down = 1, zigzag = 0;
    while(index < size)
    {
        record[i].push_back(s[index]);
        index++;

        if(down == 1)
        {
            i++;
            if( i == numRows)
            {
                down = 0;
                zigzag = 1;
                i -= 2;
            }
        }

        else if(zigzag == 1)
        {
            i--;
            if( i == -1)
            {
                zigzag = 0;
                down = 1;
                i += 2;
            }
        }
    }

    string result = "";
    for(const vector<char>& nums : record)
    {
        for (char ch : nums)
        {
            result += ch;
        }
    }
    return result;
}

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;
    cout<<convert(s,numRows);
    return 0;
}
// Date: 15.3.25