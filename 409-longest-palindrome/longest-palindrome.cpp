class Solution {
public:
    int longestPalindrome(string s) {
        int count[128]={0};
        for(char c: s){
            count[c]++;
        }
        int lenght=0;
        bool hasodd=false;

        for(int i=0;i<128;i++){
            lenght+=(count[i]/2)*2;

            if(count[i]%2!=0){
                hasodd=true;
            }
        }
        if(hasodd){
            lenght+=1;
        }
        return lenght;

    }
};