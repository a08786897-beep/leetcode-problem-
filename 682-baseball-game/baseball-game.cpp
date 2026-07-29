class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;

        for(const string& op:operations){
            if(op=="+"){
                ans.push_back(ans[ans.size()-1] + ans[ans.size()-2]);
            }else if(op=="D"){
                ans.push_back(2*ans.back());
            }else if(op=="C"){
                ans.pop_back();
            }else{
                ans.push_back(stoi(op));
            }
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
};