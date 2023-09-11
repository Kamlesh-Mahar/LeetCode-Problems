#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n == 0) return 0;

        int anchor = 0; 
        int write = 0; 

        for (int read = 0; read < n; ++read) {
            if (read == n - 1 || chars[read] != chars[read + 1]) {
                chars[write++] = chars[anchor]; 

                if (read > anchor) {
                    string countStr = to_string(read - anchor + 1);
                    for (char c : countStr) {
                        chars[write++] = c;
                    }
                }

                anchor = read + 1;
            }
        }

        return write; 
    }
};
