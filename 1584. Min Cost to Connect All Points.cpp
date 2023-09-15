class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<tuple<int, int, int>> edges;  
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({weight, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        vector<int> parent(n, -1);
        
        int minCost = 0;
        int edgesConnected = 0;
        for (const auto& edge : edges) {
            int weight = get<0>(edge);
            int u = get<1>(edge);
            int v = get<2>(edge);
            
            if (unionFind(u, v, parent)) {
                minCost += weight;
                edgesConnected++;
                
                if (edgesConnected == n - 1)
                    break;  
            }
        }
        
        return minCost;
    }
    
private:
    int findParent(int x, vector<int>& parent) {
        if (parent[x] == -1)
            return x;
        return parent[x] = findParent(parent[x], parent);
    }
    
    bool unionFind(int u, int v, vector<int>& parent) {
        int parentU = findParent(u, parent);
        int parentV = findParent(v, parent);
        
        if (parentU != parentV) {
            parent[parentU] = parentV;
            return true;  
        }
        
        return false;  
    }
};
