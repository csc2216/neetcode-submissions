class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while(l < r) {
            while (!isalnum(s[l])) {
                l++;
            }
            while (!isalnum(s[r])) {
                r--;
            }
            if (l > r) return true;

            char cl = tolower(s[l]);
            char cr = tolower(s[r]);

            if (cl != cr) return false;

            l++;
            r--;
        }
        return true;
    }
};
