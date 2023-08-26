class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        
        int bucketSize = max(1, (maxNum - minNum) / (n - 1));
        int bucketCount = (maxNum - minNum) / bucketSize + 1;
        
        vector<pair<int, int>> buckets(bucketCount, make_pair(INT_MAX, INT_MIN));
        
        for (int num : nums) {
            int index = (num - minNum) / bucketSize;
            buckets[index].first = min(buckets[index].first, num);
            buckets[index].second = max(buckets[index].second, num);
        }
        
        int maxGap = 0;
        int prevMax = minNum;
        
        for (int i = 0; i < bucketCount; ++i) {
            if (buckets[i].first == INT_MAX) {
                continue;
            }
            maxGap = max(maxGap, buckets[i].first - prevMax);
            prevMax = buckets[i].second;
        }
        
        return maxGap;
    }
};
