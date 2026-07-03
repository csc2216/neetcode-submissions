class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> substr;
        int l = 0, length = 0;

        for (int i = 0; i < s.length(); i++) {
            while(substr.count(s[i])) {
                substr.erase(s[l]);
                l++;
            }
            substr.insert(s[i]);
            length = max(length, i - l + 1);
        }
        return length;
    }
};
