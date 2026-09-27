class Solution {
public:
    string reverseParentheses(string s) {
        string res="";
        vector<int> openend;

        for( char ch : s){
            if(ch=='('){
                openend.push_back(res.length());
            }else if(ch==')'){
                int start=openend.back();
                openend.pop_back();

                reverse(res.begin()+start,res.end());
            }else{
                res+=ch;
            }
        }
        return res;
    }
};