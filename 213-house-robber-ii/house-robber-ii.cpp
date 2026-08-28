class Solution {
public:
    int helper(vector<int>& nums,int st,int end){
        int n=nums.size();

        int prev1=nums[st];
        int prev2=max(nums[st],nums[st+1]);
        int res=prev2;

        for(int i=st+2,j=2;i<=end;i++,j++){
            res=max(prev2,prev1+nums[i]);

            prev1=prev2;
            prev2=res;
        }
        return res;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        if(nums.size()==2) return max(nums[0],nums[1]);

        return max(helper(nums,1,nums.size()-1),helper(nums,0,nums.size()-2));
    }
};