class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;

        int max_so=nums[0];
        int min_so=nums[0];
        int res=max_so;

        for(size_t i=1;i<nums.size();i++){
            int curr=nums[i];

            if(curr<0){
                swap(max_so,min_so);
            }

            max_so=max(curr,max_so*curr);
            min_so=min(curr,min_so*curr);

            res=max(res,max_so);
        }
        return res;

    }
};