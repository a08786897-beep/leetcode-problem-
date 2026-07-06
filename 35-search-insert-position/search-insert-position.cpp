class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n= nums.size();
        int ans=n;
        int low=0,height=n-1;
        while(low<= height){
            int mid=low+(height-low)/2;
            if(nums[mid] >= target){
                ans=mid;
                height=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};