// https://leetcode.com/problems/search-suggestions-system/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie = new Trie();
        for(int i = 0; i < products.size(); ++i) {
            trie->insert(products[i], i);
        }
        vector<int> indices;
        vector<vector<string>> ans(searchWord.size());
        for(int i = 0; i < searchWord.size(); ++i) {
            if(!trie) break;
            trie = trie->suggest(searchWord[i], 3, indices);
            for(int p : indices) {
                ans[i].push_back(products[p]);
            }
            indices.clear();
        }
        return ans;
    }

    class Trie {
    private:
        Trie* child[26];
        int wordIndex;

    public:
        Trie() {
            fill(child, child + 26, nullptr);
            wordIndex = -1;
        }
        
        void insert(const string& word, int idx) {
            Trie* node = this;
            for(char ch : word) {
                if(!node->child[ch - 'a']) {
                    node->child[ch - 'a'] = new Trie();
                }
                node = node->child[ch - 'a'];
            }
            node->wordIndex = idx;
        }
        
        Trie* suggest(char ch, int limit, vector<int>& out_indices) {
            if(!child[ch - 'a']) {
                return nullptr;
            }
            child[ch - 'a']->getIndices(limit, out_indices);
            return child[ch - 'a'];
        }

        void getIndices(int limit, vector<int>& out_indices) {
            if(~wordIndex) {    // isEnd
                out_indices.push_back(wordIndex);
            }
            for(int i = 0; i < 26; ++i) {
                if(out_indices.size() == limit) return;
                if(!child[i]) continue;
                child[i]->getIndices(limit, out_indices);
            }
        }
    };
};