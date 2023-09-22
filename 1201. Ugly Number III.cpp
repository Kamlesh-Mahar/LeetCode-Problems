class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long left = min(min(a, b), c);
        long long right = left * n;
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long count = countDivisible(mid, a, b, c);
            
            if (count >= n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return static_cast<int>(left);
    }
    
private:
    long long gcd(long long x, long long y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }
    
    long long lcm(long long x, long long y) {
        return x / gcd(x, y) * y;
    }
    
    long long countDivisible(long long num, long long a, long long b, long long c) {
        return num / a + num / b + num / c
            - num / lcm(a, b) - num / lcm(b, c) - num / lcm(a, c)
            + num / lcm(a, lcm(b, c));
    }
};
