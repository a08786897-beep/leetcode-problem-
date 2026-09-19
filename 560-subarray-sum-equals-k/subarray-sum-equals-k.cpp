class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int prex=0,count=0;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            prex+=nums[i];
            int remove=prex-k;
            count+=mpp[remove];
            mpp[prex]+=1;
        }
        return count;
    }
};