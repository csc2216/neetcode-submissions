class Solution {
public:
    bool isValid(string s) {
        stack<char> lp, wait_for;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (c == '(' || c == '{' || c == '[') {
                lp.push(c);

                if (c == '(') wait_for.push(')');
                    else if (c == '{') wait_for.push('}');
                        else wait_for.push(']');

            } else if (wait_for.empty()) {
                return false;
            } else if (c == wait_for.top()) {
                lp.pop();
                wait_for.pop(); 
            } else return false;
        }

        if (lp.empty() && wait_for.empty()) return true;
            else return false;
    }
};
