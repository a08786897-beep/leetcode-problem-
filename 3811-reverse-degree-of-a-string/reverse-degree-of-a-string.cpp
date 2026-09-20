class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            int string_pos=i+1;

            int rev_al=26-(s[i]-'a');

            sum+=string_pos*rev_al;
        }
        return sum;
    }
};