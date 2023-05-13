class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> arr;
        int low = 0;
        int high = n-1;
        for(int i=0; i<n; i++){
            if(numbers[low]+numbers[high] > target)
                high--;   
            if(numbers[low]+numbers[high] < target)
                low++; 
            if(numbers[low]+numbers[high] == target){
                     arr.push_back(low+1);
                     arr.push_back(high+1);
                     return arr;
                }
        }
        return arr;
    }
};