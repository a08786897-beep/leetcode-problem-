class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int bit = 1;

        while (num > 0) {
            if ((num & 1) == 0) {
                ans |= bit;
            }

            bit <<= 1;
            num >>= 1;
        }

        return ans;
    }
};