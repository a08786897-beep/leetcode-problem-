class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        unordered_set<char> mp;
        for(int i=0;i<jewels.size();i++){
            mp.insert(jewels[i]);
        }
        for(int i=0;i<stones.size();i++){
            if(mp.count(stones[i])){
                count++;
            }
        }
        return count;
    }
};