using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int maxFruits = 0; 
        int left = 0;
        unordered_map<int, int> fruitCount; 

        for (int right = 0; right < tree.size(); ++right) {
            fruitCount[tree[right]]++;
            while (fruitCount.size() > 2) {
                fruitCount[tree[left]]--; 
                if (fruitCount[tree[left]] == 0) {
                    fruitCount.erase(tree[left]); 
                }
                left++; 
            }

            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};
