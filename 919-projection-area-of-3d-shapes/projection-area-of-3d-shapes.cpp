class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int total=0;
        for(int i=0;i<n;i++){
            int maxrow=0;
            int maxcol=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    total++;
                }
                maxrow=max(maxrow,grid[i][j]);
                maxcol=max(maxcol,grid[j][i]);
            }
            total+=maxrow+maxcol;
        }
        return total;
    }
};