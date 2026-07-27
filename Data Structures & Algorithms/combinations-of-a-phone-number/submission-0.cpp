class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        const vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string s = "";
        vector<string> res;
        backtrack(digits, mapping, 0, s, res);
        return res;
    }

private:
    void backtrack(const string& digits, const vector<string>& mapping, int start, string& s, vector<string>& res) {
        if (start == digits.length()) {
            res.push_back(s);
            return;
        }

        const string letters = mapping[digits[start] - '0'];

        for (char c : letters) {
            s.push_back(c);
            backtrack(digits, mapping, start + 1, s, res);
            s.pop_back();
        }
    }
};
