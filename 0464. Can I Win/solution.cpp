class Solution {
private:
    unordered_map<int,bool> mem;
    bool dfs(int max_choose, int total, int chosen) {
        if (total <= 0) return false;
        if (mem.count(chosen)) return mem[chosen];
        for (int i = 0; i < max_choose; i++) {
            if ( !(chosen & (1<<i)) && 
                 !dfs(max_choose, total-(i+1), chosen|(1<<i)) ) {
                mem[chosen] = true;
                return true;
            }
        }
        mem[chosen] = false;
        return false;
    }
public:
    bool canIWin(int max_choose, int total) {
        int choose_sum = (1 + max_choose) * max_choose / 2;
        if (max_choose >= total) return true;
        if (choose_sum < total) return false;
        if (choose_sum == total) return max_choose % 2;
        return dfs(max_choose, total, 0);
    }
};