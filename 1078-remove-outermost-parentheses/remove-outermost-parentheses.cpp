class Solution {
public:
    string removeOuterParentheses(string s) {
        string result="";
        int count=0;
        for(char ch : s){
            if(ch=='('){
                count++;

                if(count>1){
                    result += ch;
                }

            }else{
                count--;

                if(count>0){
                    result+= ch;
                }
            }
        }
        return result;
    }
};