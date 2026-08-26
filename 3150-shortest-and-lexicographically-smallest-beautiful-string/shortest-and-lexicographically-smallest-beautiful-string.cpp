class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int oneCount=0;
        int left=0;
        string res="";

        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                oneCount++;
            }

            while(oneCount==k){

                string curr=s.substr(left,i-left+1);

                if(res.empty()|| curr.length()<res.length()){
                    res=curr;
                }else if(res.length()==curr.length()){
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