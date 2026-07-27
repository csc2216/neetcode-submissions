class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> split;
        vector<vector<string>> res;
        backtrack(s, 0, split, res);
        return res;
    }

private:
    bool checkPalindrome(int l, int r, const string& s) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    void backtrack(const string& s, int start, vector<string>& split, vector<vector<string>>& res) {
        if (start == s.length()) {
            res.push_back(split);
            return;
        }
        for (int i = start; i < s.length(); i++) {
            if (checkPalindrome(start, i, s)) {
                split.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1, split, res);
                split.pop_back();
            }
        }
    }
};
