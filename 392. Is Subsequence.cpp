class Solution {
public:
    bool isSubsequence(string s, string t) {
        int stringS = 0;
        int stringT = 0;

        while(stringS < s.size() && stringT < t.size()){
            if(s[stringS]==t[stringT]){
                stringS++;
            }
            stringT++;
        }
        return stringS == s.size();
    }
};
