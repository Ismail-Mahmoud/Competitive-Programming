// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
public:
    Trie* child[26];
    bool isEnd;

    Trie() {
        fill(child, child + 26, nullptr);
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char ch : word) {
            if(!node->child[ch - 'a']) {
                node->child[ch - 'a'] = new Trie();
            }
            node = node->child[ch - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char ch : word) {
            if(!node->child[ch - 'a']) {
                return false;
            }
            node = node->child[ch - 'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char ch : prefix) {
            if(!node->child[ch - 'a']) {
                return false;
            }
            node = node->child[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */