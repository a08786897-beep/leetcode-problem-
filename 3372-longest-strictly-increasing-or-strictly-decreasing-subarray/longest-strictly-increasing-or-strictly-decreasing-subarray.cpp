class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();

        int inc=1;
        int dre=1;
        int res=1;

        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc++;
                dre=1;
                res=max(res,inc);
            }else if(nums[i]<nums[i-1]){
                dre++;
                inc=1;
                res=max(res,dre);
            }else{
                inc=1;
                dre=1;
            }
        }
        return res;
    }
};