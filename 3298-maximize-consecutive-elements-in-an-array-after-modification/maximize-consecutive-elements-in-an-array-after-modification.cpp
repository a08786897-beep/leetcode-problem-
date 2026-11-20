class Solution {
public:
    int n;
    vector<vector<int>> memo;
    int Findmethod(vector<int>& nums,int start,int target){
        int j=lower_bound(nums.begin()+start,nums.end(),target)-nums.begin();

        if(j<n && nums[j]==target){
            return j;
        }
        return -1;
    }
    int solve(int i,int inc,vector<int> & nums)
    {
        if(memo[i][inc]!=-1){
            return memo[i][inc];
        }
        int currval=nums[i]+inc;
        int len=1;

        int j=Findmethod(nums,i+1,currval+1);
        if(j!=-1){
            len=max(len,1+solve(j,0,nums));
        }
        j=Findmethod(nums,i+1,currval);
        if(j!=-1){
            len=max(len,1+solve(j,1,nums));
        }
        return memo[i][inc]= len;
    }
    int maxSelectedElements(vector<int>& nums) {
        n=nums.size();

        sort(nums.begin(),nums.end());
        memo.assign(n+1,vector<int>(2,-1));
        int res=1;

        for(int i=0;i<n;i++){
            res=max({res,solve(i,0,nums),solve(i,1,nums)});
        }
        return res;
        
    }
};