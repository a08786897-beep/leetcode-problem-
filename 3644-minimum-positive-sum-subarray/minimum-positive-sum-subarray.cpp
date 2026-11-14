class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        vector<int> prefix(n+1,0);

        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }

        int ans=INT_MAX;
        multiset<int> outidx;

        for(int i=l;i<=n;i++){
            outidx.insert(prefix[i-l]);

            if(i-r-1>=0){
                outidx.erase(outidx.find(prefix[i-r-1]));
            }
            auto it =outidx.lower_bound(prefix[i]);
            if(it != outidx.begin()){
                --it;
                ans=min(ans,prefix[i]-*it);
            }
        }
        return (ans==INT_MAX) ? -1:ans;
    }
};