class RandomizedSet {
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (indexMap.find(val) != indexMap.end()) {
            return false;
        }

        values.push_back(val);
        indexMap[val] = values.size() - 1;

        return true;
    }
    
    bool remove(int val) {
        if (indexMap.find(val) == indexMap.end()) {
            return false;
        }

        int lastValue = values.back();
        int indexToRemove = indexMap[val];

        values[indexToRemove] = lastValue;
        indexMap[lastValue] = indexToRemove;

        values.pop_back();
        indexMap.erase(val);

        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % values.size();
        return values[randomIndex];
    }

private:
    vector<int> values;
    unordered_map<int, int> indexMap;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
