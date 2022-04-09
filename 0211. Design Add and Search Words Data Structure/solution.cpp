class TrieNode {
public:
    TrieNode *next[26];
    bool end;
};

class WordDictionary {
private:
    TrieNode *head;
    bool search_trie(string & word, int index, TrieNode *node) {
        if (index == word.size()) {
            return (node != nullptr && node->end)? true:false;
        }
        if (node == nullptr) return false;
        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (search_trie(word, index+1, node->next[i]))
                    return true;
            }
            return false;
        } else {
            return search_trie(word, index+1, node->next[word[index]-'a']);
        }
    }
public:
    WordDictionary() {
        head = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *trie = head;
        for (auto c : word) {
            if (trie->next[c-'a'] == nullptr) {
                trie->next[c-'a'] = new TrieNode();
            }
            trie = trie->next[c-'a'];
        }
        trie->end = true;
    }
    
    bool search(string word) {
        return search_trie(word, 0, head);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */