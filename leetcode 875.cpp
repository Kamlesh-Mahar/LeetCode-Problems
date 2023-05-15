class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1;
        int right = getMaxPile(piles);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canEatAll(piles, H, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    int getMaxPile(vector<int>& piles) {
        int maxPile = 0;
        for (int pile : piles) {
            maxPile = max(maxPile, pile);
        }
        return maxPile;
    }
    bool canEatAll(vector<int>& piles, int H, int k) {
        int hours = 0;
        
        for (int pile : piles) {
            hours += (pile + k - 1) / k; 
        }
        
        return hours <= H;
    }
};