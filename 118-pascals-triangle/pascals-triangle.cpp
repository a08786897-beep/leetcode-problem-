class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tringle;

        for(int i=0;i<numRows;i++){
            vector<int> row(i+1,1);

            for(int j=1;j<i;j++){
                row[j]=tringle[i-1][j-1]+tringle[i-1][j];
            }

            tringle.push_back(row);
        }
        return tringle;
    }
};