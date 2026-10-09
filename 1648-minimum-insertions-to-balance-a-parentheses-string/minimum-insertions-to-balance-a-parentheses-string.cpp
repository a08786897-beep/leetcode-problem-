class Solution {
public:
    int minInsertions(string s) {
       int ans=0;
       int right=0;

       for(char c:s){
        if(c=='('){
            if(right%2!=0){
                ans++;
                right--;
            }
            right+=2;
        }else{
            right--;

            if(right<0){
                ans++;
                right+=2;
            }
        }
       }
       return ans+right;
    }
};