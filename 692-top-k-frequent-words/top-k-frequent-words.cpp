class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>freqmap;

        for(string& word:words){
            freqmap[word]++;
        }

        vector<string> uni;

        for(auto& pair : freqmap){
            uni.push_back(pair.first);
        }

        sort(uni.begin(),uni.end(),[&](string& a,string& b){
            if(freqmap[a] != freqmap[b]){
                return freqmap[a]>freqmap[b];
            }
            return a<b;
        });

        return vector<string> (uni.begin(),uni.begin()+k);
    }
};