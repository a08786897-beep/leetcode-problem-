class Solution {
public:
    bool isVowels(char ch){
        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        string str="";
        for(char ch : s){
            if(isVowels(ch)){
                str.push_back(ch);

            }
        }
        sort(str.begin(),str.end());
        string res="";
        int vowelsIdx=0;

        for(int i=0;i<s.size();i++){
            if(isVowels(s[i])){
                res.push_back(str[vowelsIdx]);
                vowelsIdx++;
            }else{
                res.push_back(s[i]);
            }
        }
        return res;
    }
};