class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;

        unordered_map<int, vector<int>> stops;  
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                stops[stop].push_back(i);
            }
        }

        queue<pair<int, int>> q;  
        unordered_set<int> visitedStops;  
        unordered_set<int> visitedRoutes;  

        for (int route : stops[S]) {
            q.push({route, 1});
            visitedRoutes.insert(route);
        }

        while (!q.empty()) {
            int currentRoute, stopsCount;
            tie(currentRoute, stopsCount) = q.front();
            q.pop();

            for (int stop : routes[currentRoute]) {
                if (stop == T) return stopsCount; 

                if (visitedStops.count(stop) == 0) {
                    visitedStops.insert(stop);

                    for (int nextRoute : stops[stop]) {
                        if (visitedRoutes.count(nextRoute) == 0) {
                            q.push({nextRoute, stopsCount + 1});
                            visitedRoutes.insert(nextRoute);
                        }
                    }
                }
            }
        }

        return -1;  
    }
};
