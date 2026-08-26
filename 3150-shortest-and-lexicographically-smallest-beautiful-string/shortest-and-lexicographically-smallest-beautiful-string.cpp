class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int left=0;
        int oneCount=0;
        string res="";

        for(int right=0;right<n;right++){
            if(s[right]=='1'){
                oneCount++;
            }


            while(oneCount==k){
                string curr=s.substr(left,right-left+1);

                if(res.empty() || curr.length() < res.length() ){
                    res=curr;
                }else if(curr.length()==res.length()){
                    res=min(res,curr);
                }


                if(s[left]=='1'){
                    oneCount--;
                }
                left++;
            }
        }
        return res;
    }
};