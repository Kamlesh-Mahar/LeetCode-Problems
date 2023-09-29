class Solution {
 public:
  int minimumSwap(string s1, string s2) {int xy = 0; 
    int yx = 0;  

    for (int i = 0; i < s1.length(); ++i) {
      if (s1[i] == s2[i])
        continue;
      if (s1[i] == 'x')
        ++xy;
      else
        ++yx;
    }

    if ((xy + yx) % 2 == 1)
      return -1;
    return xy / 2 + yx / 2 + (xy % 2 == 1 ? 2 : 0);
  }
};
