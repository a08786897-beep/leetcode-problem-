class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        long long totalOps=1LL * k1 + k2;
        vector<int> freq(100005,0);
        long long totalDiffSum=0;
        int maxDiff=0;

        for(int i=0;i<n;i++){
            int d=abs(nums1[i]-nums2[i]);
            if(d>0){
                freq[d]++;
                totalDiffSum+=d;
                maxDiff=max(maxDiff,d);

            }
        }

        if(totalDiffSum<=totalOps){
            return 0;
        }

        for(int d=maxDiff;d>0 && totalOps>0;--d){
            if(freq[d]>0){
                long long reduceCount=min((long long)freq[d],totalOps);
                freq[d]-=reduceCount;
                freq[d-1]+=reduceCount;
                totalOps-=reduceCount;
            }
        }

        long long minSum=0;
        for(int d=1;d<=maxDiff;d++){
            if(freq[d]>0){
                minSum+=1LL*freq[d]*d*d;
            }
        }
        return minSum;
    }
};