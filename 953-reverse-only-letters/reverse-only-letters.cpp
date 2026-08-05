class Solution {
public:
    bool Character(char ch){
        if((ch>='A' && ch<='Z') ||(ch>='a' && ch<='z')){
            return true;
        }
        return false;
    }
    string reverseOnlyLetters(string s) {
        int high=s.size()-1;
        int low=0;
        while(low<high){
            if(!Character(s[low])){
                low++;
            }else if(!Character(s[high])){
                high--;
            }
            else{
                swap(s[low],s[high]);
                low++;
                high--;;
            }
        }
        return s;
    }
};