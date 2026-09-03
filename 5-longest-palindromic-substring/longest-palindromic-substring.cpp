class Solution {
private:
    int CheckPalindrom(string s,int left,int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--,right++;
        }
        return right-left-1;
    }
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";

        int start=0,maxLenght=0;

        for(int i=0;i<s.length();i++){

            int len1=CheckPalindrom(s,i,i);
            int len2=CheckPalindrom(s,i,i+1);

            int len=max(len1,len2);

            if(len>maxLenght){
                maxLenght=len;
                start=i-(len-1)/2;
            }
        }
        return s.substr(start,maxLenght);
    }
};