class Solution {
public:
    void backtrack(int start,int target,int k , vector<int> &current, vector<vector<int>>& res){
        if(current.size()==k){
            if(target==0){
                res.push_back(current);
            }
            return;
        }
        for(int i=start;i<=9;i++){
            if(i>target){
                break;
            }
            current.push_back(i);
            backtrack(i+1,target-i,k,current,res);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> current;
        backtrack(1,n,k,current,res);
        return res;
    }
};