class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1= 0;
        int rob2 = 0;
        for(auto n: nums){
            int temp = max(n+rob1 , rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};