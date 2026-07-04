class Solution {
public:
    string minWindow(string s, string t) {
        int s_length = s.length(), t_length = t.length();
        
        if (s_length < t_length) return "";

        unordered_map<char, int> t_count;
        for (char c : t) {
            t_count[c]++;
        }
        int need = t_count.size();
        int have = 0;
        bool valid = false;
        int start = 0, end = 0;
        string result = "";

        int l = 0;
        for (int r = 0; r < s_length; r++) {
            char c = s[r];

            if (t_count.count(c)) {
                t_count[c]--;

                if (t_count[c] == 0) {
                    have++;
                }
            }

            while (have == need) {
                if (valid == false || r - l <= end - start) {
                    start = l;
                    end = r;
                }
                valid = true;

                char lc = s[l];
                if (t_count.count(lc)) {
                    t_count[lc]++;

                    if (t_count[lc] > 0) have--;
                }
                l++;
            }  
        }
        result = (valid) ? s.substr(start, end - start + 1) : "";
        return result;
    }
};
