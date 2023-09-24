class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        vector<int> lastOccurrence(10, -1);
        for (int i = 0; i < n; i++) {
            lastOccurrence[numStr[i] - '0'] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 9; j > (numStr[i] - '0'); j--) {
                if (lastOccurrence[j] > i) {
                    swap(numStr[i], numStr[lastOccurrence[j]]);
                    return stoi(numStr);
                }
            }
        }
        return num;
    }
};
