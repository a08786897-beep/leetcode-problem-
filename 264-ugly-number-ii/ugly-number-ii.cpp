class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0]=1;
        int p3=0,p5=0,p2=0;
        for(int i=1;i<n;i++){
            int next2=ugly[p2]*2;
            int next3=ugly[p3]*3;
            int next5=ugly[p5]*5;

            int next_ugly=min({next2,next3,next5});
            ugly[i]=next_ugly;

            if(next_ugly==next2) p2++;
            if(next_ugly==next3) p3++;
            if(next_ugly==next5) p5++;
        }
        return ugly[n-1];
    }
};