#include<bits/stdc++.h>
using namespace std;
class Trie
{
public:
    bool end;
    Trie* children[26];

    Trie()
    {
        end = false;
        for(int i = 0;i<26;i++)
        {
            children[i] = NULL;
        }
    }
    void insert( string word )
    {
    Trie*node = this;
    for(auto i: word)
    {
        if(node->children[i - 'a']== NULL)
        {
            node->children[i-'a']  = new Trie();
        }
        node = node->children[i-'a'];
    }
    node->end = true;
}

string search(string word)
{
    Trie *node = this;
    if(node->children[word[0]-'a']==NULL) 
    return word;

    string ans = "";
    for(auto i: word)
    {
        if(node->end==true) 
        break;

        if(node->children[i-'a']== NULL)
        {
            return word;
        }
        ans += i; 
        node = node->children[i-'a'];
    } 
    return ans;
}
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie*root = new Trie;

        for(auto i: dictionary) 
        {
            root->insert(i);
        }
        string word;
        istringstream iss(sentence);
        string ANS = "";
        while(getline(iss,word,' '))
        {

            ANS = ANS +root->search(word) + " ";  
        }
        ANS.pop_back();
        return ANS;
    }
};
