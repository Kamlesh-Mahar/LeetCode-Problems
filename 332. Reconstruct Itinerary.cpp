using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multimap<string, bool>> graph;
        for (const vector<string>& ticket : tickets) {
            graph[ticket[0]].emplace(ticket[1], false);
        }

        vector<string> itinerary;
        itinerary.push_back("JFK"); 
        
        dfs("JFK", tickets.size(), graph, itinerary);

        return itinerary;
    }

private:
    bool dfs(string currAirport, int remainingTickets, unordered_map<string, multimap<string, bool>>& graph, vector<string>& itinerary) {
        if (remainingTickets == 0) {
            return true; 
        }

        if (graph.find(currAirport) == graph.end()) {
            return false;  
        }

        multimap<string, bool>& flights = graph[currAirport];

        for (auto& flight : flights) {
            if (!flight.second) {
                flight.second = true;
                itinerary.push_back(flight.first);

                if (dfs(flight.first, remainingTickets - 1, graph, itinerary)) {
                    return true;
                }
                itinerary.pop_back();
                flight.second = false;
            }
        }

        return false;
    }
};
