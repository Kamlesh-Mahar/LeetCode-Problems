#include <vector>

class MyHashSet {
private:
    std::vector<bool> data;
public:
    MyHashSet() : data(1000001, false) {}
    
    void add(int key) {
        if (key >= data.size()) {
            data.resize(key + 1, false);
        }
        data[key] = true;
    }
    
    void remove(int key) {
        if (key < data.size()) {
            data[key] = false;
        }
    }
    bool contains(int key) {
        if (key < data.size()) {
            return data[key];
        }
        return false;
    }
};