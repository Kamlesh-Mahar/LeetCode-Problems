class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int longest = 0;
        for(int num: nums){
            set.insert(num);
        }
        for(int num: nums){
            if(!set.count(num-1)){
                int currentValue = num;
                int currentSeq = 1;
                while(set.count(currentValue+1)){
                    currentValue++;
                    currentSeq++;
                }
                longest = max(longest, currentSeq);
            }
        }
        return longest;
    }
};
