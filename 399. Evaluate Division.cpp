class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;

    double dfs(const string& start, const string& end, unordered_set<string>& visited) {
        if (graph[start].find(end) != graph[start].end()) {
            return graph[start][end];
        }

        for (const auto& neighbor : graph[start]) {
            if (visited.find(neighbor.first) == visited.end()) {
                visited.insert(neighbor.first);
                double result = dfs(neighbor.first, end, visited);

                if (result != -1.0) {
                    return graph[start][neighbor.first] * result;
                }
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            const string& a = equations[i][0];
            const string& b = equations[i][1];
            double value = values[i];

            graph[a][b] = value;
            graph[b][a] = 1.0 / value;
        }

        vector<double> results;

        for (const auto& query : queries) {
            const string& start = query[0];
            const string& end = query[1];

            if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
                results.push_back(-1.0);
            } else if (start == end) {
                results.push_back(1.0);
            } else {
                unordered_set<string> visited;
                double result = dfs(start, end, visited);
                results.push_back(result);
            }
        }

        return results;
    }
};
