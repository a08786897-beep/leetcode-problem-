class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int top=0;
        int bottom=n-1;
        int i=0;
        int j=n-1;

        int num=1;

        while(top<=bottom && i<=j){
            for(int left=i;left<=j;++left){
                matrix[top][left]=num++;
            }
            top++;


            for(int left=top;left<=bottom;left++){
                matrix[left][j]=num++;
            }
            j--;


            if(top<=bottom){
                for(int left=j;left>=i;left--){
                    matrix[bottom][left]=num++;
                }
                bottom--;
            }

            if(i<=j){
                for(int left=bottom;left>=top;left--){
                    matrix[left][i]=num++;
                }
                i++;
            }
        }
        return matrix;
    }
};