class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long max_product=nums[n-1]*nums[n-2];
        long long min_product=nums[0]*nums[1];

        return max_product-min_product;
    }
};