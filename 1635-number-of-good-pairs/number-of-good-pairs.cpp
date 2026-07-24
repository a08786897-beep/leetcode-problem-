class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count=0;
        unordered_map<int,int> mp;
        int i=0,j=i+1;
        for(int num : nums){
            // mp.insert(nums[i]);
            if(mp.find(num)!=mp.end()){
                count+= mp[num];
            }
            mp[num]++;
        }
        return count;
    }
};