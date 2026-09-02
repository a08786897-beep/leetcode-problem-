class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int res = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long total_hours = 0;

            for (int pile : piles) {
                total_hours += (pile + mid - 1) / mid;
            }

            if (total_hours <= h) {
                // mid is a possible answer
                res = mid;
                high = mid - 1;
            } 
            else {
                // Need to eat faster
                low = mid + 1;
            }
        }

        return res;
    }
};