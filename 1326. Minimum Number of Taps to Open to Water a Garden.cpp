class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> intervals;
        
        for (int i = 0; i <= n; ++i) {
            intervals.push_back({max(0, i - ranges[i]), min(n, i + ranges[i])});
        }
        
        sort(intervals.begin(), intervals.end());
        
        int taps = 0;
        int i = 0, currEnd = 0, nextEnd = 0;
        
        while (i < intervals.size() && currEnd < n) {
            while (i < intervals.size() && intervals[i].first <= currEnd) {
                nextEnd = max(nextEnd, intervals[i].second);
                ++i;
            }
            
            if (currEnd == nextEnd) return -1;
            
            currEnd = nextEnd;
            ++taps;
        }
        
        return currEnd >= n ? taps : -1;
    }
};
