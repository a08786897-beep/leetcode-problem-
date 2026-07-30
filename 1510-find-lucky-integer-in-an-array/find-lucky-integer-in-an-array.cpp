class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> s;
        for(int num : arr){
            s[num]++;
        }
        int max_l=-1;
        for(auto& pair : s){
            if(pair.first==pair.second){
                max_l=max(max_l,pair.first);
            }
        }
        return max_l;
    }
};