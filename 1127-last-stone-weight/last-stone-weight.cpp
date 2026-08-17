class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> meap(stones.begin(),stones.end());

        while(meap.size()>1){
            
            int stones1=meap.top();
            meap.pop();


            int stones2=meap.top();
            meap.pop();

            if(stones1 != stones2){
                meap.push(stones1-stones2);
            }
        }
        return meap.empty()?0:meap.top();
    }
};