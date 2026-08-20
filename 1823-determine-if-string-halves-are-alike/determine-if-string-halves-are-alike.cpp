class Solution {
public:

    bool isvowail(char ch){
        if(ch=='a' || ch=='A' || ch=='e' || ch=='E'|| ch=='i' || ch=='I' || ch=='o' || ch=='O' || ch=='u'  || ch=='U'){
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        int n=s.size();
        int leftCount=0;
        int rightCount=0;

        for(int i=0;i<n/2;i++){
            if(isvowail(s[i])){
                leftCount++;
            }
            if(isvowail(s[i+(n/2)])){
                rightCount++;
            }
        }
        
        
        return leftCount==rightCount;
    }
};