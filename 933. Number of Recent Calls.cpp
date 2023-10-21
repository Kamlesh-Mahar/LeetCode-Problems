class RecentCounter {
public:
    RecentCounter() {
        
    }
    int ping(int t) {
        while (!calls.empty() && calls.front() < t - 3000) {
            calls.pop();
        }
        
        calls.push(t);
        return calls.size();
    }

private:
    queue<int> calls;
};


/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
