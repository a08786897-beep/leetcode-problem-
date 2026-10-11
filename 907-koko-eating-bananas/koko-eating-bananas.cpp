class Solution {
public:
    int maxElement(const std::vector<int>& piles) {
        int maxEle = INT_MIN;
        for (int p : piles) {
            maxEle = std::max(maxEle, p);
        }
        return maxEle;
    }

    // Using pure integer arithmetic for ceil division
    long long CeilFun(const std::vector<int>& piles, int h) {
        long long totalTime = 0;
        for (int p : piles) {
            totalTime += (p + h - 1) / h;
        }
        return totalTime;
    }

    int minEatingSpeed(std::vector<int>& piles, int h) {
        int low = 1, high = maxElement(piles);
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = CeilFun(piles, mid);
            
            if (totalH <= h) {
                high = mid - 1; // Try to find a smaller valid speed
            } else {
                low = mid + 1;  // Speed is too slow, need to eat faster
            }
        }
        return low;
    }
};