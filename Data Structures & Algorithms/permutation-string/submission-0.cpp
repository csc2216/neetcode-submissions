class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();

        if (n1 > n2) return false;

        vector<int> s1_count(26, 0), s2_count(26, 0);

        for (int i = 0; i < n1; i++) {
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }
        if (s1_count == s2_count) return true;

        for (int i = n1; i < n2; i++) {
            s2_count[s2[i - n1] - 'a']--;
            s2_count[s2[i] - 'a']++;
            if (s1_count == s2_count) return true;
        }
        return false;
    }
};
