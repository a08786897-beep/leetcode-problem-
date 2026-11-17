class Solution {
public:
    int n;
    string str;
    vector<vector<int>> costmemo;
    vector<vector<int>> memo;
    int getcost(int i,int j){
        int len=j-i+1;
        if(costmemo[i][j]!=-1){
            return costmemo[i][j];
        }

        int minCost=INT_MAX;

        for(int d=1;d<len;d++){
            if(len%d !=0){
                continue;
            }
            int cost=0;
            for(int group=0;group<d;group++){
                int l=i+group;
                int r=l+(len/d-1)*d;

                while(l<r){
                    if(str[l]!=str[r]){
                        cost++;
                    }
                    l+=d;
                    r-=d;
                }
            }
            minCost=min(minCost,cost);
        }
        return costmemo[i][j]=minCost;
    }

    int solve(int start,int k){
        if(k==0){
            if(start==n) return 0;
            return INT_MAX;
        }
        if(start+2*k>n){
            return INT_MAX;
        }

        if(memo[start][k]!=-1){
            return memo[start][k];
        }
        int res=INT_MAX;

        for(int end=start+1;end<n;end++){
            int remain=solve(end+1,k-1);

            if(remain==INT_MAX){
                continue;
            }

            res=min(res,getcost(start,end)+remain);

        }
        return memo[start][k]=res;

    }
    int minimumChanges(string s, int k) {
        n=s.size();
        str=s;

        costmemo.assign(n+1,vector<int>(n+1,-1));
        memo.assign(n+1,vector<int>(k+1,-1));


        return solve(0,k);
        
    }
};