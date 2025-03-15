#include <iostream>
using namespace std;

// Problem statement - https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

int strStr(string haystack, string needle)
{
    int size1 = haystack.size();
    int size2 = needle.size();

    int start = 0;
    int flag  = 0;
    for(int i = 0, j = 0; i < size1 && j < size2;)
    {
        if(haystack[i] == needle[j])
        {
            if(j==0)
            {
                start = i;
                flag = 1;
            }

            i++;
            j++;
            if(j == size2)
            {
                return start;
            }
        }

        else if(flag == 1)
        {
            flag = 0;
            j = 0;
            i = start + 1;
        }

        else
        {
            i++;
            j = 0;
        }
    }
    return -1;
}

int main()
{
    string haystack = "sasadbutsad";
    string needle = "sad";
    cout<<strStr(haystack , needle);
    return 0;
}
// Date: 15.3.25