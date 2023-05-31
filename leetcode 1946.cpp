#include <string>

class Solution {
public:
    std::string maximumNumber(std::string num, std::vector<int>& change) {
        bool mutationStarted = false;
        int n = num.length();
        
        for (int i = 0; i < n; i++) {
            int digit = num[i] - '0';
            
            if (change[digit] > digit) {
                num[i] = change[digit] + '0';
                mutationStarted = true;
            }
            else if (change[digit] < digit) {
                if (mutationStarted)
                    break;
            }
        }
        
        return num;
    }
};