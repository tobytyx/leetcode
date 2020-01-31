# include <iostream>
# include <unordered_map>
# include <vector>
# include <algorithm>
using namespace std;

class RandomizedSet {
public:
    unordered_map<int, int> map;
    vector<int> list;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.find(val) != map.end()) return false;
        list.push_back(val);
        map[val] = list.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map.find(val) == map.end()) return false;
        int val_back = list[list.size()-1];
        swap(list[map[val]], list[list.size()-1]);
        map[val_back] = map[val];
        list.pop_back();
        map.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return list[rand() % list.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */