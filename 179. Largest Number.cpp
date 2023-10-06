class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStrs;
        for (int num : nums) {
            numStrs.push_back(to_string(num));
        }
        sort(numStrs.begin(), numStrs.end(), [](string& a, string& b) {
            return a + b > b + a;
        });
        if (numStrs[0] == "0") {
            return "0";
        }
        string result = "";
        for (string& numStr : numStrs) {
            result += numStr;
        }

        return result;
    }
};
