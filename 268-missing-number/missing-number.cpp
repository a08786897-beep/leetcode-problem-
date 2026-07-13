class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sumpre=(n*(n+1))/2;
        int sumact=0;
        for(int i =0;i<n;i++){
            sumact+=nums[i];
        }
        return sumpre-sumact;
    }
};