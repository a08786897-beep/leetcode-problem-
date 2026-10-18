class Solution {
private:
    int sum(vector<int>& nums){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        return sum;
    }

    int func(vector<int>& nums,int L){
        int split=0,arr=1;
        for(int i=0;i<nums.size();i++){
            if(split+nums[i]<=L){
                split+=nums[i];
            }else{
                arr++;
                split=nums[i];
            }
        }
        return arr;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<k) return -1;
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int noofpan=func(nums,mid);
            if(noofpan>k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};