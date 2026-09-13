class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int cost=0;
        int maxpro=0;
        int minbuy=prices[0];

        for(int i =0;i<n;i++){
            cost=prices[i]-minbuy;

            maxpro=max(maxpro,cost);
            minbuy=min(minbuy,prices[i]);
            

        }
        return maxpro;
    }
};