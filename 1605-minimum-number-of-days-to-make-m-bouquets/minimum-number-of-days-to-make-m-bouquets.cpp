class Solution {
public:
    bool posibile(vector<int>& bloomDay,int day,int m, int k){
        int n=bloomDay.size();
        int cnt=0;
        int noOF=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day){
                cnt++;
            }else{
                noOF+=(cnt/k);
                cnt=0;
            }
        }
        noOF+=(cnt / k);
        return noOF>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int minEl=INT_MAX,maxEl=INT_MIN;
        for(int i=0;i<n;i++){
            minEl=min(minEl,bloomDay[i]);
            maxEl=max(maxEl,bloomDay[i]);
        }
        int low=minEl,high=maxEl;
        long long val = (long long)m * k;
        if(val>n) return -1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(posibile(bloomDay,mid,m,k)==true){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};