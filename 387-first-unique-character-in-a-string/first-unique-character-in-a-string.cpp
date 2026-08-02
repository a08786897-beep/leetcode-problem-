class Solution {
public:
    int firstUniqChar(string s) {
        int count[26]={0};
        queue<int> q;
        int n=s.size();
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
            q.push(i);

            while(!q.empty() &&count[s[q.front()]-'a']>1){
                q.pop();
            }
        }
        return q.empty()?-1:q.front();
    }
};