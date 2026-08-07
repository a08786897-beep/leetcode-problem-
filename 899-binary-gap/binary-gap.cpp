class Solution {
public:
    int binaryGap(int n) {
        int maxgap=0;
        int lastposition=-1;
        int currentposition=0;

        while(n>0){
            if((n&1)==1){
                if(lastposition != -1){
                    maxgap=max(maxgap,currentposition-lastposition);
                }
                lastposition=currentposition;
            }
            currentposition++;
            n>>=1;
        }
        return maxgap;
    }
};