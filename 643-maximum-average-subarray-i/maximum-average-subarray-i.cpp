class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double  curr=0;
        for(int i=0;i<k;i++){
            curr+=nums[i];
        }

        double max1=curr;

        for(int i=k;i<nums.size();i++){
            curr+=nums[i]-nums[i-k];

            max1=max(max1,curr);
        }
        return max1/k;
    }
};