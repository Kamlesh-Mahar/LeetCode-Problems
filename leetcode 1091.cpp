#include <vector>

class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        int maxCandies = 0;
        for (int candy : candies) {
            maxCandies = std::max(maxCandies, candy);
        }
        std::vector<bool> result;
        for (int candy : candies) {
            if (candy + extraCandies >= maxCandies) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        
        return result;
    }
};