class Solution {
public:
    int sum(vector<int>& nums){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        return sum;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum=sum(nums);

        if(abs(target)>totalSum || (target+totalSum)%2!=0){
            return 0;
        }
        int subSum=(target+totalSum)/2;
        vector<int> dp(subSum+1,0);
        dp[0]=1;


        for(int num:nums){
            for(int j=subSum;j>=num;--j){
                dp[j]+=dp[j-num];
            }
        }
        return dp[subSum];
    }
};