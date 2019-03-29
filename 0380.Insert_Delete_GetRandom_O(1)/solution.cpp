#include <iostream>
#include <vector>
#include <map>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hash_table.find(val) != hash_table.end())
            return false;
        nums.push_back(val);
        hash_table[val] = nums.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hash_table.find(val) == hash_table.end())
            return false;
        nums[hash_table[val]] = nums.back();
        hash_table[nums.back()] = hash_table[val];
        nums.pop_back();
        hash_table.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
private:
    vector<int> nums;
    map<int,int> hash_table;
};

int main() {
    RandomizedSet* obj = new RandomizedSet();
    cout << "insert 5 " << obj->insert(5) << endl;
    cout << "insert 3 " << obj->insert(3) << endl;
    cout << "insert 4 " << obj->insert(4) << endl;
    cout << "insert 8 " << obj->insert(8) << endl;
    cout << "insert 9 " << obj->insert(9) << endl;
    cout << "remove 3 " << obj->remove(3) << endl;
    cout << "remove 8 " << obj->remove(8) << endl;
    cout << "remove 9 " << obj->remove(9) << endl;
    cout << "get random " << obj->getRandom() << endl;
    return 0;
}