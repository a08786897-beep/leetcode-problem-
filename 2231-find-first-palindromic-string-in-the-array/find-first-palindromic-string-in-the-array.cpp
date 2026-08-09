class Solution {
private:
    bool isPalindromic(string& s){
        int left=0;
        int right=s.length()-1;

        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(string& word: words){
            if(isPalindromic(word)){
                return word;
            }
        }
        return "";
    }
};