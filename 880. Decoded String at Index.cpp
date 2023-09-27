class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long size = 0; 
        for (char ch : S) {
            if (isdigit(ch)) {
                size *= (ch - '0'); 
            } else {
                size++; 
            }
        }
        for (int i = S.size() - 1; i >= 0; i--) {
            K %= size; 
            if (K == 0 && isalpha(S[i])) {
                string result = "";
                result += S[i];
                return result;
            }
            
            if (isdigit(S[i])) {
                size /= (S[i] - '0');
            } else {
                size--;
            }
        }
        
        return ""; 
    }
};
