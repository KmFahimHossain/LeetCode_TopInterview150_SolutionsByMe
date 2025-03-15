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

    int size = s.size();
    int numCols = (size/(2*numRows - 2) + 1)*(numRows-1);
    vector<vector<char>> record(numRows, vector<char>(numCols,'0'));

    int i = 0, j = 0, down = 1, zigzag = 0, index = 0;
    while(index < size)
    {
        record[i][j] = s[index];
        index++;

        if(down == 1)
        {
            i++;
            if( i == numRows)
            {
                down = 0;
                zigzag = 1;
                i -= 2;
                j++;
            }
        }
    
        else if(zigzag == 1)
        {
            i--;
            j++;
            if( i == -1)
            {
                zigzag = 0;
                down = 1;
                i += 2;
                j--;
            }
        }
    }

    string result = "";
    for(vector<char>& nums : record)
    {
        for (char ch : nums)
        {
            if ( ch != '0')
            {
                result += ch;
            }
            // cout<<ch<<" ";
        }
        // cout<<endl;
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