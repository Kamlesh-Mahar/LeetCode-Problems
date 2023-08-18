class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> graph(n);
        
        for (const vector<int>& road : roads) {
            graph[road[0]].insert(road[1]);
            graph[road[1]].insert(road[0]);
        }
        
        int maxRank = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int rank = graph[i].size() + graph[j].size();
                if (graph[i].count(j)) {
                    rank -= 1; 
                }
                maxRank = max(maxRank, rank);
            }
        }
        
        return maxRank;
    }
};
