#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> sets;
        size_t found = 0;
        for (vector<string>::iterator it = emails.begin(); it != emails.end(); it++) {
            while ((found = it->find_first_of(".+@"), found) != string::npos) {
                if (it->at(found) == '.')
                    it->erase(found, 1);
                else if (it->at(found) == '+')
                    it->erase(found, it->find_first_of('@')-found);
                else if (it->at(found) == '@')
                    break;
            }
            sets.insert(*it);
        }
        return sets.size();
    }
};

int main() {
#if 0
    vector<string> emails{"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
#elif 1
    vector<string> emails{"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
#endif
    Solution solution;
    cout << solution.numUniqueEmails(emails) << endl;
    return 0;
}