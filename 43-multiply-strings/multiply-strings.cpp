class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";

        int n=num1.size();
        int m=num2.size();

        vector<int> ans(n + m , 0);

        for(int i=n-1 ; i >= 0; i--){
            for(int j=m-1 ; j>=0 ; j--){
                int mul=((num1[i]-'0') * (num2[j]-'0'));

                int p1=i+j;
                int p2=i+j+1;

                int sum = mul + ans[p2];

                ans[p2]=sum%10;
                ans[p1]+=sum/10;
            }
        }
        string prod="";

        for(int num : ans){
            if(!(prod.empty() && num==0)){
                prod.push_back(num + '0');
            }
        }
        return prod.empty()?"0" : prod;

    }
};