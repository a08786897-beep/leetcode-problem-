class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int Pairof_maxSum=0;
        for(int i=0;i<nums.size();i+=2){
            Pairof_maxSum+=nums[i];
        }
        return Pairof_maxSum;
    }
};