class Trie {
public:
    int count;
    Trie* childs[26];
    Trie() {
        for (int i = 0; i < 26; ++i)
            childs[i] = nullptr;
        count = 0;
    }
};

class Solution {
public:
    void insert(string word, Trie* root) {
        Trie* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->childs[idx] == NULL) {
                curr->childs[idx] = new Trie();
            }
            curr = curr->childs[idx];
            curr->count++;
        }
    }

    int countOfPrefixWord(Trie* root, string prefix) {
        Trie* curr = root;
        int cnt = 0;
        for (char c : prefix) {
            int ind = c - 'a';
            if (curr->childs[ind] == NULL) {
                return 0;
            }
            curr = curr->childs[ind];
            cnt += curr->count;
        }
        return cnt;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> arr(words.size(), 0);
        Trie* root = new Trie();
        for (string& keys : words) {
            insert(keys, root);
        }
        for (int i = 0; i < words.size(); i++) {
            int sum = countOfPrefixWord(root, words[i]);
            arr[i] = sum;
        }
        return arr;
    }
};
