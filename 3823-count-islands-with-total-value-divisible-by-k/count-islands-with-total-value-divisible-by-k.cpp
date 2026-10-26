class Solution {
public:
    bool isvaild(vector<vector<int>>& grid, int i,int j){
        int m=grid.size();
        int n=grid[0].size();
        if(i>=0 && j>=0 && i<m && j<n && grid[i][j]){
            return true;
        }
        return false;
    }
    long long dfs(vector<vector<int>>& grid, int i, int j) {
        long long sum = grid[i][j];
        grid[i][j] = 0; // Mark current cell as visited
        
        // Directions for moving Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for (int d = 0; d < 4; d++) {
            int ni = i + dr[d];
            int nj = j + dc[d];
            if (isvaild(grid, ni, nj)) {
                sum += dfs(grid, ni, nj);
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        long long sum=0;
        int count=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    sum=dfs(grid,i,j);
                    if(sum%k==0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};