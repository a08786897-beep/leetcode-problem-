class Solution {
public:
    int lower(vector<int>& nums, int target,int n){
        int low=0,high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }

        }
        return ans;
    }
    int Upper(vector<int>& nums, int target,int n){
        int low=0,high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }

        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=lower(nums,target,nums.size());
        int n=nums.size();
        if(lb==n || nums[lb]!=target) return {-1,-1};
        return {lb,Upper(nums,target,nums.size())-1};
    }
};