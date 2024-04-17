const int SIZE = 26;
class Trie{
public:
    char node;
    pair<int,int> st;
    Trie* ar[SIZE];
    Trie(char c){
        this->node = c;
        for(int i=0;i<26;i++) this->ar[i] = NULL;
    }
};

class Solution {

    void insert(Trie* root,string& s,int ind,int len){
        Trie* tempRoot = root;
        for(int i=0;i<s.size();i++){
            int index = s[i]-'a';
            if(tempRoot->ar[index]==NULL){
                tempRoot->ar[index] = new Trie(s[i]);
                tempRoot->ar[index]->st = {len,ind};
            }
            tempRoot = tempRoot->ar[index];
            if((tempRoot->st).first>len){
                tempRoot->st = {len,ind};
            }
           
        }
    }

    pair<int,int> search(Trie* root,string& s){
        Trie* temp = root;
        int n = s.size();
        for(int i=0;i<n;i++){
            int ind = s[i]-'a';
            if(temp->ar[ind]==NULL){
                int index = (temp->st).second;
                return temp->st;
            }
            temp = temp->ar[ind];
        }
        int last = (temp->st).second;
        return temp->st;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie* trie = new Trie('#');
        int minLen = 1e6, ind = 1e6;
        for(int i=0;i<wordsContainer.size();i++){
            string wordTemp = wordsContainer[i];
            int n = wordTemp.size();
            if(n<minLen){
                minLen = n;
                ind = i;
            }
            reverse(wordTemp.begin(),wordTemp.end());
            insert(trie,wordTemp,i,n);
        }       
        trie->st = {minLen,ind};
        vector<int> ans;
        for(string word:wordsQuery){
            string wordTemp = word;
            int n = word.size();
            reverse(wordTemp.begin(),wordTemp.end());
            pair<int,int> ind1 = search(trie,wordTemp);
            cout << ind1.first << " " << ind1.second << endl;
            ans.push_back(ind1.second);
        }
        return ans;
    }
};
