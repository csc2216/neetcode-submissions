class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (int i = 0; i < tokens.size(); i++) {
            string c = tokens[i];

            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int r = nums.top();
                nums.pop();
                int l = nums.top();
                nums.pop();

                if (c == "+") nums.push(l + r);
                else if (c == "-") nums.push(l - r);
                else if (c == "*") nums.push(l * r);
                else if (c == "/") nums.push(l / r);

            } else nums.push(stoi(c)); 
        }    
        return nums.top();
    }
};
