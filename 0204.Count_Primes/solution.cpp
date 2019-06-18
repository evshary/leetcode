#include <iostream>
#include <vector>
using namespace std;

#if 1 // using table to make quicker
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n, true);
        for (int i = 2; i * i < n; i++) {
            if (!primes[i]) continue;
            for (int j = i + i; j < n; j += i) {
                primes[j] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++)
            if (primes[i]) count++;
        return count;
    }
};
#else
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrimeNum(i)) {
                //cout << i << endl;
                count++;
            }
        }
        return count;
    }
private:
    bool isPrimeNum(int num) {
        if (nums.size() == 0) {
            nums.push_back(false);
            nums.push_back(true);
        }
        //cout << nums.size() << " " << num << endl;
        for (int tmp = nums.size()+1; tmp <= num; tmp++) {
            int i;
            for (i = 2; i * i <= num; i++) {
                if (nums[i-1] && num % i == 0) {
                    nums.push_back(false);
                    break;
                }
            }
            if (i > num/i) nums.push_back(true);
        }
        return nums[num-1];
    }
    vector<bool> nums;
};
#endif

int main() {
    Solution s;
    vector<int> problems{1,2,3,4,5,6,7,8,9,10,100,499979,999983};
    //vector<int> problems{5};
    for (auto p : problems)
        cout << p << ":" << s.countPrimes(p) << endl;
    return 0;
}