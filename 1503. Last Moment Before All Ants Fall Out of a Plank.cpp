class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int lastMoment = 0;
        
        if (!left.empty()) {
            int maxLeft = *max_element(left.begin(), left.end());
            lastMoment = max(maxLeft, lastMoment);
        }
    
        if (!right.empty()) {
            int minRight = *min_element(right.begin(), right.end());
            lastMoment = max(n - minRight, lastMoment);
        }
        
        return lastMoment;
    }
};
