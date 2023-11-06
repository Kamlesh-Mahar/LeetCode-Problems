class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(isConnected, visited, i, n);
            }
        }

        return provinces;
    }

private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node, int n) {
        visited[node] = true;
        for (int i = 0; i < n; i++) {
            if (isConnected[node][i] == 1 && !visited[i]) {
                dfs(isConnected, visited, i, n);
            }
        }
    }
};
