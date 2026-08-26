class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxSum=0;
        int left=0,right=nums.size()-1;
        while(left<right){
            int sum=nums[left]+nums[right];
            maxSum=max(maxSum,sum);
            left++,right--;
        }
        return maxSum;
    }
};