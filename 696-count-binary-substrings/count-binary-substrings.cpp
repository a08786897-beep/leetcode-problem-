class Solution {
public:
    int countBinarySubstrings(string s) {
        int total=0;
        int prev=0;
        int curr=1;

        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                curr++;
            }else{
                total+=min(prev,curr);
                prev=curr;
                curr=1;
            }
        }
        total+=min(prev,curr);
        return total;
    }
};