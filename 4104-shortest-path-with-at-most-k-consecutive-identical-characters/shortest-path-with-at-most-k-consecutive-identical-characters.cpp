class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            g[u].emplace_back(v, w);
        }

        // dist[u][cur] stores the minimum weight to reach node u with `cur` consecutive identical characters
        vector<vector<long long>> dist(n, vector<long long>(k + 1, 1e18));
        dist[0][1] = 0;

        // Min-priority queue storing tuples of (weight, node, consecutive_count)
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
        pq.emplace(0, 0, 1);

        while (!pq.empty()) {
            auto [d, u, cur] = pq.top();
            pq.pop();

            if (u == n - 1) {
                return d;
            }

            if (d > dist[u][cur]) {
                continue;
            }

            for (const auto& [v, w] : g[u]) {
                int nxt = (labels[v] == labels[u]) ? (cur + 1) : 1;
                long long nd = d + w;

                if (nxt <= k && nd < dist[v][nxt]) {
                    dist[v][nxt] = nd;
                    pq.emplace(nd, v, nxt);
                }
            }
        }

        return -1;
    }
};