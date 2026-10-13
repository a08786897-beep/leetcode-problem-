class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long> seq(n);

        for(int i=0;i<n;i++){
            long long val=nums[i];
            seq[i]=val*val;
        }

        sort(seq.begin(),seq.end());

        long long ans=0;
        int ngc=n/2;

        for(int i=0;i<ngc;i++){
            ans-=seq[i];
        }
        for(int i=ngc;i<n;i++){
            ans+=seq[i];
        }
        return ans;
    }
};