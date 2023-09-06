class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;

        if(n<0){
            x = 1/x;
            
            if(n==INT_MIN){
                x *= x;
                n /= 2;
            }
            n = -n;
        }

        return (n%2 == 0) ? myPow(x*x, n/2): x * myPow(x*x, n/2);
    }
};