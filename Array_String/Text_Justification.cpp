#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/text-justification/description/

vector<int> spaceRecords(vector<string>& words, int maxWidth, int startIndex)
{
    int currentWidth = words[startIndex].size();
    int wordCount = 1;
    while( startIndex+wordCount < words.size() && currentWidth + words[startIndex+wordCount].size() + 1 <= maxWidth)
    {
        currentWidth += words[startIndex+wordCount].size() + 1;
        wordCount++;
    }
    int spaceNeeded = maxWidth - currentWidth;
    int spaceCount = wordCount - 1;

    if(spaceCount == 0)
    {
        if(spaceNeeded > 0)
        {
            // cout<<spaceNeeded<<"_"<<-1<<endl;
            return {spaceNeeded,-1};
        }
        else
        {
            // cout<<spaceNeeded<<"_"<<1<<endl;
            return {spaceNeeded,0};
        }
    }

    vector<int> spaceRecord(spaceCount, 1);
    int index = 0;
    while( spaceNeeded != 0)
    {
        spaceRecord[index%spaceCount]++;
        index++;
        spaceNeeded--;
    }
    spaceRecord.push_back(spaceCount);
    // for(int x : spaceRecord)
    // {
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return spaceRecord;
}

string leftJustify(string s, int maxWidth)
{
    string newString = "";
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != ' ' || s[i+1] != ' ')
        {
            newString.push_back(s[i]);
        }
    }
    newString.append(maxWidth - newString.size() , ' ');
    return newString;
}

vector<string> fullJustify(vector<string>& words, int maxWidth)
{
    if(words.size() == 1)
    {
        return {leftJustify(words.back(), maxWidth)};
    }

    vector<string> newStrings;
    int startIndex = 0;
    while(startIndex < words.size())
    {
        vector<int> spaceRecord = spaceRecords(words, maxWidth, startIndex);
        int wordCount = spaceRecord[spaceRecord.size() - 1];
        spaceRecord.pop_back();

        string line = "";
        if(wordCount == -1)
        {
            line += words[startIndex];
            line.resize(maxWidth,' ');
            startIndex++;
        }
        else
        {
            for(int i = 0; i < wordCount && startIndex + i < words.size(); i++)
            {
                line += words[startIndex + i];
                line.append(spaceRecord[i], ' ');
            }
            line += words[startIndex + wordCount];
            startIndex += wordCount + 1;
        }
        newStrings.push_back(line);
    }
    newStrings.back() = leftJustify(newStrings.back(), maxWidth);
    return newStrings;
}

int main()
{
    vector<string> words = {"What","must","be","acknowledgment","abilities","be","abilities","be"};
    int maxWidth = 16;
    vector<string> result = fullJustify(words, maxWidth);

    for(string line : result)
    {
        cout<<"_"<<line<<"_"<<endl;
    }
    return 0;
}
// Date: 16.3.25