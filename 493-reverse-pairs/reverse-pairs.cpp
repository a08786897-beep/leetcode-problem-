class Solution {
public:
    void merge(vector<int>& nums, int st, int mid, int end) {
        vector<int> temp;
        int i = st, j = mid + 1;

        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= end) temp.push_back(nums[j++]);

        for (int k = 0; k < temp.size(); k++) {
            nums[st + k] = temp[k];
        }
    }

    int countPairs(vector<int>& nums, int st, int mid, int end) {
        int count = 0;
        int r = mid + 1;

        for (int i = st; i <= mid; i++) {
            while (r <= end &&
                   (long long)nums[i] > 2LL * nums[r]) {
                r++;
            }
            count += r - (mid + 1);
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int st, int end) {
        if (st >= end) return 0;

        int mid = st + (end - st) / 2;

        int count = 0;

        count += mergeSort(nums, st, mid);
        count += mergeSort(nums, mid + 1, end);

        count += countPairs(nums, st, mid, end);

        merge(nums, st, mid, end);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};