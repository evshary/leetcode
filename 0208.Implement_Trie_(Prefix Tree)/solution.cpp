#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode *next[26];
    bool end;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        start = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = start;
        for (int i = 0; i < word.size(); i++) {
            if (node->next[word[i]-'a'] == 0) {
                node->next[word[i]-'a'] = new TrieNode();
            }
            node = node->next[word[i]-'a'];
        }
        node->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = start;
        for (int i = 0; i < word.size(); i++) {
            if (node->next[word[i]-'a'] == 0) {
                return false;
            }
            node = node->next[word[i]-'a'];            
        }
        if (node->end)
            return true;
        return false;    
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = start;
        for (int i = 0; i < prefix.size(); i++) {
            if (node->next[prefix[i]-'a'] == 0) {
                return false;
            }
            node = node->next[prefix[i]-'a'];            
        }
        return true;
    }
private:
    TrieNode *start;
};

int main() {
    Trie *obj = new Trie();
    string word("apple");
    string prefix("app");
    obj->insert(word);
    cout << "search " << word;
    if (obj->search(word))
        cout << ":true" << endl;
    else
        cout << ":false" << endl;
    cout << "start with " << prefix;
    if (obj->startsWith(prefix))
        cout << ":true" << endl;
    else
        cout << ":false" << endl;
    delete obj;
    return 0;
}