class Solution {
public:
    int binarySearch(vector<int>& nums,int low,int high, int target){
        low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int left=0,high=nums.size()-1;
        return binarySearch(nums,left,high,target);
    }
};