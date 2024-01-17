class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurrenceMap;

        for (int num : arr) {
            occurrenceMap[num]++;
        }

        unordered_set<int> occurrenceSet;

        for (const auto& entry : occurrenceMap) {
            if (occurrenceSet.count(entry.second) > 0) {
                return false;
            }
            occurrenceSet.insert(entry.second);
        }

        return true;
    }
};
