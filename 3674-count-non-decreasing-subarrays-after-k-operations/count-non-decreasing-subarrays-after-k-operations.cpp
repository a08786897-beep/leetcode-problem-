class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        deque<pair<int,int>> dq;
        int n=nums.size();
        int j=n-1;
        int i=j;
        long long operation=0;
        while(i>=0){
            int newEle=nums[i];
            int popCount=0;
            while(!dq.empty() && dq.front().first<=newEle){
                operation+=(newEle-dq.front().first)*1LL*dq.front().second;
                popCount+=dq.front().second;
                dq.pop_front();
            }
            dq.push_front({newEle,popCount+1});

            if(operation<=k){
                ans+=1LL*(j-i+1);
            }else{
                while(i<j && operation>k){
                    auto [bottemVal,bottemCount]=dq.back();
                    operation-=(bottemVal-nums[j]);
                    dq.pop_back();
                    if(bottemCount-1>0){
                        dq.push_back({bottemVal,bottemCount-1});
                    }
                    j--;
                }
                ans+=1LL*(j-i+1);
            }
            i--;
        }
        return ans;

    }
};