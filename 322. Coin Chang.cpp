
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int total = 0, count=0;
        int quan = sizeof(coins);
        for(int i = quan; i>0; i--){
            count = 0;
            for(int j = quan; j>0; j--){
                if(j<amount){
                    total= total + j;
                    count++;
                    j++;
                    if(total == amount){
                        return count;
                    }
                }
            }
        }
        return 0;
    }
};