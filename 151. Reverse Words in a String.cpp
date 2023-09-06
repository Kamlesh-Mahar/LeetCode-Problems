#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        string result = "";
        while (iss >> word) {
            if (!result.empty()) {
                result = " " + result;
            }
            result = word + result; 
        }

        return result;
    }
};
