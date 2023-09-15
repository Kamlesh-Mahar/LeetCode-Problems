class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(10001, 0);
        for (int num : nums) {
            count[num]++;
        }
        int prevPrev = 0;
        int prev = 0;
        int maxPoints = 0;

        for (int i = 1; i <= 10000; i++) {
            int maxWithCurrent = max(prevPrev + i * count[i], prev);
            prevPrev = prev;
            prev = maxWithCurrent;
            maxPoints = max(maxPoints, maxWithCurrent);
        }

        return maxPoints;
    }
};
