class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        unordered_set<int> visited;
        return dfs(arr, start, visited);
    }

private:
    bool dfs(vector<int>& arr, int currIndex, unordered_set<int>& visited) {
        if (currIndex >= 0 && currIndex < arr.size() && visited.find(currIndex) == visited.end()) {
            visited.insert(currIndex);
            if (arr[currIndex] == 0) return true;
            return dfs(arr, currIndex + arr[currIndex], visited) || dfs(arr, currIndex - arr[currIndex], visited);
        }
        
        return false;
    }
};
