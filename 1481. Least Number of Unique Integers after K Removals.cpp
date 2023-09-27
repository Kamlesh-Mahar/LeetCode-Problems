class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for (int num : arr)
            freq[num]++;
        vector<int> frequencies;
        for (auto& pair : freq) {
            frequencies.push_back(pair.second);
        }
        sort(frequencies.begin(), frequencies.end());
        int uniqueIntegers = frequencies.size();

        for (int freq : frequencies) {
            if (k >= freq) {
                k -= freq;
                uniqueIntegers--;
            } else {
                break;
            }
        }

        return uniqueIntegers;
    }
};
