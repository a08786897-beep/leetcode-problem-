class Solution {
    bool canAssign(int mid,int n,vector<int>& quantity){
        int count=0;
        for(int i=0;i<quantity.size();i++){
            count += ceil((double)quantity[i]/mid);
        }
        return count <= n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantity) {
        int low=1;
        int high=*max_element(quantity.begin(),quantity.end());
        int mid;
        int ans=INT_MAX;
        while(low<=high){
            mid=low+(high-low)/2;

            if(canAssign(mid,n,quantity)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};