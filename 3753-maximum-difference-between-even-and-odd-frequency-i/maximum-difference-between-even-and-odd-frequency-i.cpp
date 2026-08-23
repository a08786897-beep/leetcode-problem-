class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;

        for(char ch:s){
            mp[ch]++;
        }
        int maxOdd=INT_MIN;
        int mineven=INT_MAX;

        for(auto& pair:mp){
            int freq=pair.second;

            if(freq%2!=0){
                maxOdd=max(maxOdd,freq);
            }else{
                mineven=min(mineven,freq);
            }
        }
        return maxOdd-mineven;
    }
};