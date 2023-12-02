int countCharacters(std::vector<std::string>& words, std::string chars) {
    std::unordered_map<char, int> charCount;

    for (char ch : chars) {
        charCount[ch]++;
    }

    int result = 0;

    for (const std::string& word : words) {
        std::unordered_map<char, int> wordCount;

        bool validWord = true;

        for (char ch : word) {
            wordCount[ch]++;

            if (wordCount[ch] > charCount[ch]) {
                validWord = false;
                break;
            }
        }

        if (validWord) {
            result += word.size();
        }
    }

    return result;
}
