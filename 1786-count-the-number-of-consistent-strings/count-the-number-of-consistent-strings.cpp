class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool isAllowed[26]={false};

        for(char ch : allowed){
            isAllowed[ch-'a']=true;
        }

        int consistentCount=0;

        for(string& word:words){
            bool isConsistent=true;

            for(char ch:word){
                if(!isAllowed[ch-'a']){
                    isConsistent=false;
                    break;
                }
            }
            if(isConsistent){
                consistentCount++;
            }
        }
        return consistentCount;
    }
};