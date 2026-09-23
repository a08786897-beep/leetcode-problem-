class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n ; i++) {

            // Skip duplicates for i
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            for(int j = i + 1; j < n ; j++) {

                // Skip duplicates for j
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1;
                int l = n - 1;

                while(k < l) {

                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum == target) {

                        ans.push_back({
                            nums[i], nums[j], nums[k], nums[l]
                        });

                        k++;
                        l--;

                        // Skip duplicates
                        while(k < l && nums[k] == nums[k - 1])
                            k++;

                        while(k < l && nums[l] == nums[l + 1])
                            l--;

                    }
                    else if(sum > target) {
                        l--;
                    }
                    else {
                        k++;
                    }
                }
            }
        }

        return ans;
    }
};