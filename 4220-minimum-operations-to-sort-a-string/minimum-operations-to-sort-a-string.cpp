class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }
        if (n == 2) {
            return -1;
        }

        char min_char = s[0];
        char max_char = s[0];

        for (char ch : s) {
            min_char = min(min_char, ch);
            max_char = max(max_char, ch);
        }

        // If min is at the start or max is at the end, 1 operation is enough
        if (s[0] == min_char || s[n - 1] == max_char) {
            return 1;
        }

        // Check if any min_char or max_char exists in the interior [1, n-2]
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == min_char || s[i] == max_char) {
                return 2;
            }
        }

        return 3;
    }
};