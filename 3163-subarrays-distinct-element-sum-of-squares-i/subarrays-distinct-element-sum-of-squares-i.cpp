class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for(int i=0;i<n;i++){
            unordered_set<int> distinct;
            for(int j=i;j<n;j++){
                distinct.insert(nums[j]);
                int d=distinct.size();
                totalSum+=d*d;
            }
        }
        return totalSum;
    }
};