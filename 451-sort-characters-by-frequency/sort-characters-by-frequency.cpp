class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;

        for(char ch : s ){
            freq[ch]++;
        }

        vector<pair<char,int>> freqVal(freq.begin(),freq.end());

        sort(freqVal.begin(),freqVal.end(),[](const pair<char,int>& a, const pair<char,int>& b){
            return a.second>b.second;
        });

        string res="";

        for(auto& p:freqVal){
            res.append(p.second,p.first);
        }
        return res;
    }
};