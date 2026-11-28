class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = static_cast<int>(items.size());
        if (n == 0 || budget <= 0) {
            return 0;
        }

        vector<int> factorCount(n + 1, 0);
        long long minprice = LLONG_MAX;

        for (const auto& item : items) {
            int factor = item[0];
            long long price = item[1];

            if (factor >= 1 && factor <= n) {
                factorCount[factor]++;
            }
            if (price < minprice) {
                minprice = price;
            }
        }

        vector<int> multipleCount(n + 1, 0);
        for (int f = 1; f <= n; f++) {
            for (int m = 2 * f; m <= n; m += f) {
                multipleCount[f] += factorCount[m];
            }
            if (factorCount[f] > 0) {
                multipleCount[f] += (factorCount[f] - 1);
            }
        }

        vector<pair<long long, int>> premiumDeals;
        for (const auto& item : items) {
            int factor = item[0];
            long long price = item[1];

            int multiple = (factor >= 1 && factor <= n) ? multipleCount[factor] : 0;

            if (multiple > 0 && price > 0 && price < 2 * minprice) {
                premiumDeals.push_back({price, multiple});
            }
        }

        sort(premiumDeals.begin(), premiumDeals.end());

        long long totalitems = 0;
        long long remainbudget = budget;

        for (const auto& deal : premiumDeals) {
            if (remainbudget <= 0) {
                break;
            }
            long long price = deal.first;
            long long limit = deal.second;

            long long afford = remainbudget / price;
            long long copy = min(limit, afford);

            totalitems += copy * 2;
            remainbudget -= copy * price;
        }

        if (minprice > 0) {
            totalitems += remainbudget / minprice;
        }

        return static_cast<int>(totalitems);
    }
};