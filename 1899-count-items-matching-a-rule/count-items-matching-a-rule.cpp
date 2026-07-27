class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int index=0;

        if(ruleKey=="type"){
            index=0;
        }else if(ruleKey=="color"){
            index=1;
        }else if(ruleKey=="name"){
            index=2;
        }

        int matchMax=0;

        for(const auto& item: items){
            if(item[index]==ruleValue){
                matchMax++;
            }
        }
        return matchMax;
    }
};