class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string p = "";
        vector<string> res;
        backtrack(p, 0, 0, n, res);
        return res;
    }

private:
    void backtrack(string& p, int l, int r, int n, vector<string>& res) {
        if (l + r == 2 * n) {
            res.push_back(p);
            return;
        }

        if (l < n) {
            p.push_back('(');
            backtrack(p, l + 1, r, n, res);
            p.pop_back();
        }

        if (l > r) {
            p.push_back(')');
            backtrack(p, l, r + 1, n, res);
            p.pop_back();
        }
    }
};
