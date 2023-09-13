#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0;
        int right = A.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (A[mid] < A[mid + 1]) {
                left = mid + 1; 
            } else {
                right = mid; 
            }
        }

        return left; 
    }
};
