class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> memo; 

        for (int stone : stones) {
            memo[stone] = unordered_set<int>();
        }
        memo[0].insert(0); 

        for (int stone : stones) {
            for (int jump : memo[stone]) {
                for (int nxt_jump = jump - 1; nxt_jump <= jump + 1; ++nxt_jump) {
                    if (nxt_jump > 0 && memo.find(stone + nxt_jump) != memo.end()) {
                        memo[stone + nxt_jump].insert(nxt_jump);
                    }
                }
            }
        }

        return !memo[stones.back()].empty();
    }
};
