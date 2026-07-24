class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](const int &a,const int &b){
            int countA=__builtin_popcount(a);
            int countB=__builtin_popcount(b);

            if(countA != countB){
                return countA<countB;
            }
            return a<b;
        });
        return arr;
    }
};