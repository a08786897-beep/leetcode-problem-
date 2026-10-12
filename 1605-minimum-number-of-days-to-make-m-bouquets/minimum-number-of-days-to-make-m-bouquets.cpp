class Solution {
public:
    bool posible(vector<int>& bloomDay,int day, int m, int k){
        int n=bloomDay.size();
        int cnt=0;
        int noof=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day){
                cnt++;
            }
            else{
                noof+=(cnt/k);
                cnt=0;
            }
        }
        noof+=(cnt / k);
        return noof>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=(long long)m*k;
        int n=bloomDay.size();
        if(val>n) return -1;
        int minEl=INT_MAX,maxEl=INT_MIN;
        for(int i=0;i<n;i++){
            minEl=min(minEl,bloomDay[i]);
            maxEl=max(maxEl,bloomDay[i]);
        }
        int low=minEl,high=maxEl;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(posible(bloomDay,mid,m,k)==true){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};