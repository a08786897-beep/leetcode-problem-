class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.length()<26){
            return false;
        }

        bool seen[26]={false};
        int count=0;
        
        for(char ch:sentence){
            int index=ch-'a';
            if(!seen[index]){
                seen[index]=true;
                count++;
                if(count==26){
                    return true;
                }
            }
        }
        return false;
    }
};