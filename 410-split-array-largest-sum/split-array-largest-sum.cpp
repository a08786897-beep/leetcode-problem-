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
    int func(vector<int>& nums,int split){
        int noofSplit=0,inintialSplits=1;
        for(int i=0;i<nums.size();i++){
            if(noofSplit+nums[i]<=split){
                noofSplit+=nums[i];
            }
            else{
                inintialSplits++;
                noofSplit=nums[i];
            }
        }
        return inintialSplits;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<k) return -1;
        int low=*max_element(nums.begin(),nums.end());
        int high=sum(nums);
        while(low<=high){
            int mid=low+(high-low)/2;
            int NoofArray=func(nums,mid);
            if(NoofArray>k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};