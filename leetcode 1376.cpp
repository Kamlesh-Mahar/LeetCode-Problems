#include <vector>

class Solution {
public:
    int numOfMinutes(int n, int headID, std::vector<int>& manager, std::vector<int>& informTime) {
        std::vector<std::vector<int>> graph(n);
        
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                graph[manager[i]].push_back(i);
            }
        }
        return dfs(graph, informTime, headID);
    }
private:
    int dfs(const std::vector<std::vector<int>>& graph, const std::vector<int>& informTime, int node) {
        if (graph[node].empty()) {
            return 0; 
        }
        int maxTime = 0;
        for (int neighbor : graph[node]) {
            maxTime = std::max(maxTime, dfs(graph, informTime, neighbor));
        }
        return maxTime + informTime[node];
    }
};