#include <iostream>
#include <vector>
using namespace std;

// Problem statement - https://leetcode.com/problems/reverse-words-in-a-string/description/

string reverseWords(string s)
{
    vector<string> words;
    string word;
    string newWord;
    for(int i = 0; i < s.size(); i++)
    {
        word = "";
        while( i < s.size() && s[i] == ' ' )
        {
            i++;
        }
        while(i < s.size() && s[i] != ' ')
        {
            word += s[i];
            i++;
        }

        if(!word.empty())
        {
            words.push_back(word);
        }
    }

    for(int i = words.size() - 1; i >= 0; i--)
    {
        newWord += words[i] + " ";
    }
    newWord.pop_back();
    return newWord;
}

int main() 
{
    string s = "  the sky is   blue  ";
    cout<<"_"<<reverseWords(s)<<"_";
    return 0;
}
// Date: 16.3.25