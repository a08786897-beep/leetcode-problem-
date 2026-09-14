class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0;

        for (int w : weights) {
            low = max(low, w);
            high += w;
        }

        int res = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canship(weights, days, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }

private:
    bool canship(vector<int>& weights, int days, int capacity) {
        int dayNeed = 1;
        int currentWeight = 0;

        for (int w : weights) {
            if (currentWeight + w > capacity) {
                dayNeed++;
                currentWeight = 0;
            }

            currentWeight += w;
        }

        return dayNeed <= days;
    }
};
