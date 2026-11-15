class Solution {
public:
    int M=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();

        int sum=0;
        int count=0;
        int odd=0;
        int even=1;

        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2!=0){
                count=(count+even)%M;
                odd++;
            }else{
                count=(count+odd)%M;
                even++;
            }
        }
        return count;
    }
};