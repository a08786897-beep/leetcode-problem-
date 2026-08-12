class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int exp=(n*(n+1))/2;
        int act=0;
        for(int i=0;i<n;i++){
            act+=nums[i];
        }
        return exp-act;
    }
};