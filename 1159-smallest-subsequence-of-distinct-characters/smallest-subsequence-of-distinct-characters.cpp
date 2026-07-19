class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        vector<int> vis(26,0),cnt(26,0);
        for(auto it: s){
            cnt[it-'a']++;
        }
        string ans="";
        for(auto ch : s){
            if(!vis[ch-'a']){
                while(! ans.empty() && ans.back()>ch){
                    if(cnt[ans.back()-'a']>0){
                        vis[ans.back()-'a']=0;
                        ans.pop_back();
                    }
                    else{
                        break;
                    }
                }
            ans.push_back(ch);
            vis[ch-'a']=1;
            }

            cnt[ch-'a'] -= 1;
        }
        return ans;
    }
};