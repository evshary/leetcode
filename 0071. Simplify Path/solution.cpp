class Solution {
public:
    string simplifyPath(string path) {
        vector<string> ans_v; 
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') continue;
            string cur = "";
            while (i < path.size() && path[i] != '/') cur += path[i++];
            if (cur == ".") {
                continue;
            } else if (cur == "..") {
                if (ans_v.size()) ans_v.pop_back();
            } else {
                ans_v.push_back(cur);
            }
        }
        string ans = "";
        for (auto & s : ans_v) {
            ans += "/" + s;
        }
        return (ans.size())? ans:"/";
    }
};