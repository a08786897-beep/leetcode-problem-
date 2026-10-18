class Solution {
private:
    long long MOD=1e9+7;
    vector<vector<long long>> table;

    void precomputeCombinations(int n){
        table.assign(n+1,vector<long long>(n+1,1));

        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                table[i][j]=(table[i-1][j-1]+table[i-1][j])%MOD;
            }
        }
    }
    long long dfs(vector<int> & nums){
        if(nums.size()<=2){
            return 1;
        }
        int root=nums[0];
        vector<int> left,right;

        for(int i=1;i<nums.size();i++){
            if(nums[i]<root){
                left.push_back(nums[i]);
            }else{
                right.push_back(nums[i]);
            }
        }
        long long leftWays=dfs(left);
        long long rightWays=dfs(right);

        long long totalWays=(table[left.size()+right.size()][left.size()]*leftWays)%MOD;
        return (totalWays*rightWays)%MOD;

    }
public:
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        precomputeCombinations(n);

        return (dfs(nums)-1+MOD)%MOD;
    }
};