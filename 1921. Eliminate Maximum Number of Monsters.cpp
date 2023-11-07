class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> arrivalTime(n);

        for (int i = 0; i < n; i++) {
            arrivalTime[i] = static_cast<double>(dist[i]) / speed[i];
        }

        sort(arrivalTime.begin(), arrivalTime.end());

        for (int i = 0; i < n; i++) {
            if (i >= arrivalTime[i]) {
                return i;
            }
        }

        return n;
    }
};
