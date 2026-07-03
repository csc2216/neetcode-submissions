class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int l = 0;
        int max_length = 0;
        /* past_max_freq_in_a_substr */
        int max_freq = 0;

        for (int r = 0; r < s.length(); r++) {
            count[s[r] - 'A']++;
            max_freq = max(max_freq, count[s[r] - 'A']);

            if (r - l + 1 > max_freq + k) {
                count[s[l] - 'A']--;
                l++;
            }
            max_length = max(max_length, r - l + 1);
        }
        return max_length;
    }
};
