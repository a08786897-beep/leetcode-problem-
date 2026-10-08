class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        stack<int> st;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);

                if(st.size()>1){
                    res+='(';
                }
            }else{
                if(st.size()>=2){
                    res+=')';
                }
                st.pop();
            }
        }
        return res;
    }
};