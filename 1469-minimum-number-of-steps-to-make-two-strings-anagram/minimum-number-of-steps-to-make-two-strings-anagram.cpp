class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26,0);

        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }

        int step=0;

        for(int count:freq){
            if(count>0){
                step+=count;
            }
        }
        return step;
    }
};