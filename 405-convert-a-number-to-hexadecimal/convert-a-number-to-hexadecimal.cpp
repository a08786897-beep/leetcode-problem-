class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";

        string hex_chars = "0123456789abcdef";
        string ans = "";

        unsigned int n = num;

        while (n > 0) {
            int last_four_bits = n & 15;   // n & 0xf
            ans = hex_chars[last_four_bits] + ans;
            n >>= 4;
        }

        return ans;
    }
};