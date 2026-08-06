class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int delete1=0;
        int Numrow=strs.size();
        int Numcol=strs[0].size();

        for(int col=0;col<Numcol;col++){
            for(int row=1;row<Numrow;row++){
                if(strs[row][col]<strs[row-1][col]){
                    delete1++;
                    break;
                }
            }
        }
        return delete1;
    }
};