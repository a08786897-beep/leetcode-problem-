class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperCount=0;
        for(int i=0;i<word.size();i++){
            if(word[i]>='A' && word[i]<='Z'){
                upperCount++;
            }
        }
        if(upperCount==word.size()){
            return true;
        }
        if(upperCount==0){
            return true;
        }
        if(upperCount==1 && (word[0]>='A' && word[0]<='Z')){
            return true;
        }
        return false;
    }
};