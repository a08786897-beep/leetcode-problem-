class Solution {
public:
    void dfs(vector<vector<int>>& image , int i, int j , int orgnalcolor ,int newcolor){
        if(i<0 || j<0 || i>= image.size() || j >= image[0].size() || image[i][j] == newcolor || image[i][j] != orgnalcolor ){
            return;
        }

        image[i][j]=newcolor;

        dfs(image,i-1,j,orgnalcolor,newcolor);
        dfs(image,i,j+1,orgnalcolor,newcolor);
        dfs(image,i+1,j,orgnalcolor,newcolor);
        dfs(image,i,j-1,orgnalcolor,newcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,image[sr][sc],color);

        return image;
    }
};