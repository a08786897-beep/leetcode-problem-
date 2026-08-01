class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        vector<int>result;
        int low=0;
        int high=n;
        for(int i=0;i<n;i++){
            if(s[i]=='I'){
                result.push_back(low);
                low++;
            }if(s[i]=='D'){
                result.push_back(high);
                high--;
            }
        }
        result.push_back(low);
        return result;
    }
};