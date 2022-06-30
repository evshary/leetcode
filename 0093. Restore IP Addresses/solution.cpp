class Solution {
private:
	void traverse(vector<string>& addrs, string s, int idx, string ip, int parts) {
		if (parts == 4) {
			if (idx != s.size()) return;
			ip.pop_back();
			addrs.push_back(ip);
			return;
		}
		for (int i = 0; i < 3 && i + idx < s.size(); i++) {
			if (i == 2) {
				int num = stoi(s.substr(idx, 3));
				if (num > 255) break;
			}
			ip += s[idx+i];
			traverse(addrs, s, idx+i+1, ip + '.', parts+1);
			if (s[idx] == '0') break;
		}
		return;
	}
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        traverse(ans, s, 0, "", 0);
        return ans;
    }
};