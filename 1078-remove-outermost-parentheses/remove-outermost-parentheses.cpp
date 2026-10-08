class Solution {
public:
    string removeOuterParentheses(string s) {
       stack<int> st;
       string ans="";
       int n=s.size();
       for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push(s[i]);

            if(st.size()>1){
                ans+='(';
            }
        }else{
            if(st.size()>=2){
                ans+=')';
            }
            st.pop();
        }
       }
       return ans;
    }
};