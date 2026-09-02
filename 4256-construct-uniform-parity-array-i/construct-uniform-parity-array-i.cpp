class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        // Check if we can make all elements even
        bool allEven = true;

        for (int i = 0; i < n; i++) {
            // If nums1[i] is already even, choose nums1[i].
            // If it is odd, we need another element of opposite parity.
            if (nums1[i] % 2 != 0) {
                bool foundEven = false;

                for (int j = 0; j < n; j++) {
                    if (i != j && nums1[j] % 2 == 0) {
                        foundEven = true;
                        break;
                    }
                }

                if (!foundEven) {
                    allEven = false;
                    break;
                }
            }
        }

        if (allEven)
            return true;

        // Check if we can make all elements odd
        bool allOdd = true;

        for (int i = 0; i < n; i++) {
            // If nums1[i] is already odd, choose nums1[i].
            // If it is even, we need another element of odd parity.
            if (nums1[i] % 2 == 0) {
                bool foundOdd = false;

                for (int j = 0; j < n; j++) {
                    if (i != j && nums1[j] % 2 != 0) {
                        foundOdd = true;
                        break;
                    }
                }

                if (!foundOdd) {
                    allOdd = false;
                    break;
                }
            }
        }

        return allOdd;
    }
};