class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adjList;
        unordered_set<int> visited;
        for (const auto& pair : adjacentPairs) {
            adjList[pair[0]].push_back(pair[1]);
            adjList[pair[1]].push_back(pair[0]);
        }

        int start = 0;
        for (const auto& [node, neighbors] : adjList) {
            if (neighbors.size() == 1) {
                start = node;
                break;
            }
        }

        vector<int> result;
        dfs(start, adjList, visited, result);

        return result;
    }

private:
    void dfs(int node, const unordered_map<int, vector<int>>& adjList, unordered_set<int>& visited, vector<int>& result) {
        visited.insert(node);
        result.push_back(node);

        for (int neighbor : adjList.at(node)) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, adjList, visited, result);
            }
        }
    }
};

