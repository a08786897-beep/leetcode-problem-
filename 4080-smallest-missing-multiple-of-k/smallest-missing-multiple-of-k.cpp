class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> mp(nums.begin(),nums.end());
        int curr=k;
        while(mp.count(curr)){
            curr+=k;
        }
        return curr;
    }
};