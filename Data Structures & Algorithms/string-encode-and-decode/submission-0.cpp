class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string result = "";
        for (int i = 0; i < n; i++) {
            result += to_string(strs[i].length()) + "#" + strs[i];
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.length()) {
            int j = s.find('#', i);
            int length = stoi(s.substr(i, j - i));
            string word = s.substr(j + 1, length);
            result.push_back(word);
            i = j + length + 1; 
        }

        return result;
    }
};
