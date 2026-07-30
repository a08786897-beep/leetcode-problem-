class Solution {
public:
    int minimumPushes(string word) {
        int totalPushes=0;

        for(int i=0;i<word.size();i++){
            int pressesPer=(i/8)+1;

            totalPushes += pressesPer;
        }
        return totalPushes;
    }
};