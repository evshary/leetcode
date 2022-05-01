class Solution {
private:
    unordered_map<int, int> hash;
public:
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        if (hash.count(n)) return hash[n];
        hash[n] = fib(n-1) + fib(n-2);
        return hash[n];
    }
};