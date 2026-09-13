class Solution {
public:
    int divide(int dividend, int divisor) {

        // Overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Check whether answer should be negative
        bool isNeg = (dividend < 0) ^ (divisor < 0);

        // Convert both numbers to positive long long
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long quo = 0;

        while (a >= b) {

            long long temp = b;
            long long multiply = 1;

            // Find largest multiple of divisor
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiply <<= 1;
            }

            a -= temp;
            quo += multiply;
        }

        // Apply sign
        if (isNeg) {
            quo = -quo;
        }

        return (int)quo;
    }
};