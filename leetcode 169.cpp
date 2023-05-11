class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0];
        int count = 1;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] == maj)
                count += 1;
            else{
                count -= 1;
                if(count == 0){
                    maj = nums[i];
                    count = 1;
                }
                
            }
        }
        return maj;
    }
};