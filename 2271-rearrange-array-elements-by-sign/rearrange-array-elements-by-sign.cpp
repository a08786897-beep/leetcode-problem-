class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int post=0;
        int neg=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[post]=nums[i];
                post+=2;
            }
            else{
                ans[neg]=nums[i];
                neg+=2;
            }
        }
        return ans;

    }
};