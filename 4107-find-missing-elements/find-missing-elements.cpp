class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> missing;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            for(int missing_new=nums[i]+1;missing_new<nums[i+1];missing_new++){
                missing.push_back(missing_new);
            }
        }
        return missing;
    }
};