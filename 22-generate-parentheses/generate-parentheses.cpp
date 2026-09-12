class Solution {
public:
    void backtack(vector<string>& res,string current,int opencount,int closeCount,int n){
        if(current.length()==2*n){
            res.push_back(current);
            return ;
        }

        if(opencount<n){
            backtack(res,current+"(",opencount+1,closeCount , n);
        }

        if(closeCount<opencount){
            backtack(res,current+")",opencount,closeCount+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtack(res,"",0,0,n);
        return res;

    }
};