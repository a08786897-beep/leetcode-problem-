class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int max_el=INT_MIN;
        for(int i=0;i<n;i++){
            max_el=max(max_el,nums[i]);
        }
        for(int i=0;i<n;i++){
            sum+=max_el-nums[i];
        }
        return sum;
    }
};