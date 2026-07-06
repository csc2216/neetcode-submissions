class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> nums; 

        for (const string& c : tokens) {
            
            if (c.length() == 1 && !isdigit(c[0])) {
                int r = nums.back(); nums.pop_back();
                int l = nums.back(); nums.pop_back();

                if (c[0] == '+') nums.push_back(l + r);
                else if (c[0] == '-') nums.push_back(l - r);
                else if (c[0] == '*') nums.push_back(l * r);
                else if (c[0] == '/') nums.push_back(l / r);

            } else {
                nums.push_back(stoi(c)); 
            }
        }    
        return nums.back();
    }
};
