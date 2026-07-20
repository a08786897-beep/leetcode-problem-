class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r=grid.size();
        int c=grid[0].size();

        int total=r*c;


        vector<vector<int>> ans(r,vector<int> (c,0));

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int curr=(i*c)+j;

                int new_curr=(curr+k)%total;

                ans[new_curr/c][new_curr%c]=grid[i][j];
            }
        }
        return ans;
    }
};