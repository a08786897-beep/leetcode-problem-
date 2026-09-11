class Solution {
public:
    void backtrack(int start,int n,int k,vector<int>& current,vector<vector<int>>& res){
        if(current.size()==k){
            res.push_back(current);
            return ;
        }

        for(int i=start;i<=n-(k-current.size())+1;i++){
            current.push_back(i);
            backtrack(i+1,n,k,current,res);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> current;
        backtrack(1,n,k,current,res);
        return res;
    }
};