class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        int half=n/2;

        string first=s.substr(0,half);

        sort(first.begin(),first.end());

        string second=first;
        reverse(second.begin(),second.end());


        if(n%2 != 0){
            return first+s[half]+second;
        }else{
            return first+second;
        }
    }
};