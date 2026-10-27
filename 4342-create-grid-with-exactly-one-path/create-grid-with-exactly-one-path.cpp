class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        for(int i=0;i<m;i++){
            string curr="";

            if(i==m-1){
                for(int j=0;j<n;j++){
                    curr+='.';
                }

            }else{
                for(int j=0;j<n;j++){
                    if(j==0){
                        curr+='.';
                    }else{
                        curr+='#';
                    }
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};