class Solution {
public:
    int helperdp(int n,vector<int> &dp){
        if(n==1 || n==2) return n;

        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=helperdp(n-1,dp)+helperdp(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);

        return helperdp(n,dp);
    }
};