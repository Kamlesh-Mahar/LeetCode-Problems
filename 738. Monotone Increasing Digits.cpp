class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int n = str.length();
        int marker = n;

        for(int i = n-1; i>0; i--){
            if(str[i]<str[i-1]){
                marker = i;
                str[i-1]--;
            }
        }

        for(int i = marker; i<n; i++){
            str[i] = '9';
        }

        return stoi(str);
    }
};
