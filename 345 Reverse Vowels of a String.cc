class Solution {
public:
    string reverseVowels(string s) {
        if (s.empty()) {
            return s;
        }
        vector<char> vowels;
        for (char ch : s) {
            if (is_vowel(ch)) {
                vowels.push_back(ch);
            }
        }
        auto it = vowels.rbegin();
        for (char& ch : s) {
            if (is_vowel(ch)) {
                ch = *(it);
                ++it;
            }
        }
        return s;
    }

private:
    bool is_vowel(char c) {
        char ch = tolower(c);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};
