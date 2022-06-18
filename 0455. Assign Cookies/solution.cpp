class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0, cookie = 0;
        int content_child = 0;
        while (child < g.size() && cookie < s.size()) {
            if (s[cookie] >= g[child]) {
                content_child++;
                cookie++, child++;
            } else {
                cookie++;
            }
        }
        return content_child;
    }
};