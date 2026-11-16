class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string new_str;
            for(int i=0;i<s.size();i+=k){
                int cal=0;
                for(int j=i;j<min(i+k,(int)s.size());j++){
                    cal+=s[j]-'0';
                }
                new_str+=to_string(cal);
            }
            s=move(new_str);
        }
        return s;
    }
};