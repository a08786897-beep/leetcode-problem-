class Solution {
public:
    bool safedivide(int n) {
        int num = n;   // Store original number

        while (n > 0) {
            int r = n % 10;

            if (r == 0 || num % r != 0) {
                return false;
            }

            n /= 10;
        }

        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        for (int i = left; i <= right; i++) {
            if (safedivide(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};