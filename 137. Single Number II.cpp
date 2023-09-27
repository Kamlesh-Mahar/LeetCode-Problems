class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> trave;

        for (int num : nums){
            trave[num]++;
        }

        for(auto& pair: trave){
            if(pair.second == 1){
                return pair.first;
            }
        }
        return -1;
    }
};
