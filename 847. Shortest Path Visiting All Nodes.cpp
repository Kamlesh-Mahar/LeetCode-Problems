class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int targetMask = (1 << n) - 1; 
        vector<vector<int>> visited(n, vector<int>(1 << n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            q.push({i, 1 << i});
            visited[i][1 << i] = 1;
        }
        
        int steps = 0;
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; ++i) {
                auto [node, state] = q.front();
                q.pop();
                
                if (state == targetMask) {
                    return steps; 
                }
                
                for (int neighbor : graph[node]) {
                    int nextState = state | (1 << neighbor);
                    
                    if (!visited[neighbor][nextState]) {
                        visited[neighbor][nextState] = 1;
                        q.push({neighbor, nextState});
                    }
                }
            }
            
            steps++;
        }
        
        return -1; 
    }
};
