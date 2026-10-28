class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n=matrix.size();
       if(n==0) return false;
       int m=matrix[0].size();

       int low=0,high=m-1;

       while(low<n && high>=0){
        if(matrix[low][high]==target) return true;
        else if(matrix[low][high]<target) low++;
        else high--;
       }
       return false;
    } 
};