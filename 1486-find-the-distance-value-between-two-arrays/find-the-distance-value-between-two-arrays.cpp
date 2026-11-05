class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n1=arr1.size();
        sort(arr2.begin(),arr2.end());
        int n2=arr2.size();

        int count=0;

        for(int i=0;i<n1;i++){
            int j=lower_bound(arr2.begin(),arr2.end(),arr1[i])-arr2.begin();

            if(j==0){
                count+=(arr2[0]-arr1[i])>d;
            }else if(j>=n2){
                count+=(arr1[i]-arr2[n2-1])>d;
            }else{
                count+=(arr2[j]-arr1[i])>d && (arr1[i]-arr2[j-1])>d;
            }
        }
        return count;
    }
};