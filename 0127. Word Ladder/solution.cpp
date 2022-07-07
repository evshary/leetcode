class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // TC: O(NMM), SC: O(NM) while N is wordList.size() and M is beginWord.size()
        // There is MM in TC because we need to copy the string
        queue<string> q;
        unordered_set<string> word_hash;
        unordered_set<string> visited;
        for (auto & s : wordList) word_hash.insert(s);
        if (!word_hash.count(endWord)) return 0;
        q.push(beginWord);
   		visited.insert(beginWord);
        int change_len = 1;
        while (!q.empty()) {
        	int q_size = q.size();
        	while (q_size != 0) {
        		string curWord = q.front();
        		q.pop();
                if (curWord == endWord) return change_len;
        		for (int i = 0; i < curWord.size(); i++) {
        			string tmpWord = curWord;
        			for (char c = 'a'; c <= 'z'; c++) {
        				tmpWord[i] = c;
        				if (word_hash.count(tmpWord) && !visited.count(tmpWord)) {
        					visited.insert(tmpWord);
        					q.push(tmpWord);
        				}    
        			}
        		}
        		q_size--;
        	}
        	change_len++;
        }
        return 0;
    }
};