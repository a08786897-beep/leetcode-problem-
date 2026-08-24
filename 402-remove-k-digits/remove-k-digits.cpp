class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() <= k){
            return "0";
        }
        string res="";

        for(char ch:num){
            while(k>0 && !res.empty() && res.back()>ch){
                res.pop_back();
                k--;
            }

            res.push_back(ch);
        }

        while(k>0 && !res.empty()){
            res.pop_back();
            k--;
        }

        int nonzero=0;

        while(nonzero < res.length() && res[nonzero]=='0'){
            nonzero++;
        }

        res=res.substr(nonzero);

        return res.empty()? "0" : res;
    }
};