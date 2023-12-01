class Solution {
public:
    bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {
    string concatenatedWord1;
    string concatenatedWord2;

    for (const string& word : word1) {
        concatenatedWord1 += word;
    }

    for (const string& word : word2) {
        concatenatedWord2 += word;
    }

    return concatenatedWord1 == concatenatedWord2;
}
};
