class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = make_pair(position[i], (double)(target - position[i]) / speed[i]);
        }
        sort(cars.rbegin(), cars.rend());
        int fleetCount = 0;
        double curTime = 0;
        for (int i = 0; i < n; i++) {
            if (cars[i].second > curTime) {
                curTime = cars[i].second;
                fleetCount++;
            }
        }
        return fleetCount;
    }
};
