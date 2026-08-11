class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string word="";
        string words1="";
        for(int i=0;i<word1.size();i++){
            word+=word1[i];
        }
        for(int i=0;i<word2.size();i++){
            words1+=word2[i];
        }
        return word==words1;
    }
};