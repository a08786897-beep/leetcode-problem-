class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(n!=1){
            if(s.count(n)){
                return false;
            }
            s.insert(n);
            int sum=0;
            while(n>0){
                int r = n%10;
                sum+= r*r;
                n /= 10;
            }
            n=sum;
        }
        return true;
        
    }
};