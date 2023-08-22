class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n = A.size();
        vector<pair<int, int>> indices; 
        
        for (int i = 0; i < n; ++i) {
            indices.push_back({A[i], i});
        }
        
        sort(indices.begin(), indices.end()); 
        
        int maxRampWidth = 0;
        int minIndex = indices[0].second;
        
        for (int i = 1; i < n; ++i) {
            maxRampWidth = max(maxRampWidth, indices[i].second - minIndex);
            minIndex = min(minIndex, indices[i].second);
        }
        
        return maxRampWidth;
    }
};
