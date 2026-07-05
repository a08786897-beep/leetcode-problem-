class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
       int n= arr.size();
       int l=0;
       for(int r=0;r<n;r++){
            if(arr[l] != arr[r]){
                arr[l+1] = arr[r];
                l++;
            }
       }
       return l+1;
    }
};