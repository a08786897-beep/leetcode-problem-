class Solution {
public:
    int countAsterisks(string s) {
        int aster=0;

        bool inside=false;

        for(char ch:s){
            if(ch=='|'){
                inside=!inside;
            }else if(ch=='*' && !inside){
                aster++;
            }
        }
        return aster;
    }
};