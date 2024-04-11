class Trie {
    class TrieNode {
        public:
        char value;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char val) : value(val), isTerminal(false) {
            for (int i = 0; i < 26; ++i) {
                children[i] = NULL;
            }
        }
    };
    TrieNode* root;
    void insertWord(TrieNode* root, const string& word) {
        if (word.empty()) {
            root->isTerminal = true;
            return;
        }
        char ch = word[0];
        int index = ch - 'a';

        TrieNode* child = root->children[index];
        if (child == NULL) {
            child = new TrieNode(ch);
            root->children[index] = child;
        }
        insertWord(child, word.substr(1));
    }
    bool searchWord(TrieNode* root, const string& word) {
        if (word.empty()) {
            return root->isTerminal;
        }
        char ch = word[0];
        int index = ch - 'a';

        TrieNode* child = root->children[index];
        if (child == NULL) {
            return false;
        }
        return searchWord(child, word.substr(1));
    }
    bool startsWithPrefix(TrieNode* root, const string& word) {
        if (word.empty()) {
            return true;
        }
        char ch = word[0];
        int index = ch - 'a';

        TrieNode* child = root->children[index];
        if (child == NULL) {
            return false;
        }
      return startsWithPrefix(child, word.substr(1));
    }

public:
    Trie() {
        root = new TrieNode('#');
    }
  void insert(const string& word) {
        insertWord(root, word);
    }

    bool search(const string& word) {
        return searchWord(root, word);
    }
      bool startsWith(const string& prefix) {
        return startsWithPrefix(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
