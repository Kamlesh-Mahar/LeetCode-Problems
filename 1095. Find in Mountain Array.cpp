class Solution {
 public:
  int findInMountainArray(int target, MountainArray& mountainArr) {
    const int n = mountainArr.length();
    const int peakIndex = peakIndexInMountainArray(mountainArr, 0, n - 1);

    const int leftIndex = searchLeft(mountainArr, target, 0, peakIndex);
    if (mountainArr.get(leftIndex) == target)
      return leftIndex;

    const int rightIndex =
        searchRight(mountainArr, target, peakIndex + 1, n - 1);
    if (mountainArr.get(rightIndex) == target)
      return rightIndex;

    return -1;
  }

 private:
  int peakIndexInMountainArray(MountainArray& A, int l, int r) {
    while (l < r) {
      const int m = (l + r) / 2;
      if (A.get(m) < A.get(m + 1))
        l = m + 1;
      else
        r = m;
    }
    return l;
  }

  int searchLeft(MountainArray& A, int target, int l, int r) {
    while (l < r) {
      const int m = (l + r) / 2;
      if (A.get(m) < target)
        l = m + 1;
      else
        r = m;
    }
    return l;
  }

  int searchRight(MountainArray& A, int target, int l, int r) {
    while (l < r) {
      const int m = (l + r) / 2;
      if (A.get(m) > target)
        l = m + 1;
      else
        r = m;
    }
    return l;
  }
};
