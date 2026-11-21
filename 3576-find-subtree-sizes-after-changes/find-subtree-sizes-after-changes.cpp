class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> res;
    vector<int> last;

    void dfs(int curr, string& s, vector<int>& parent) {
        int c = s[curr] - 'a';
        int nearestAn = last[c];

        last[c] = curr;
        for (int child : adj[curr]) {
            dfs(child, s, parent);
        }
        last[c] = nearestAn;

        if (curr != 0) {
            int oldParent = parent[curr];
            int newParent = (nearestAn != -1) ? nearestAn : oldParent;

            parent[curr] = newParent;
            res[newParent] += res[curr];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        adj.clear();

        for (int i = 1; i < n; i++) {
            int u = parent[i];
            int v = i;
            adj[u].push_back(v);
        }

        res.assign(n, 1);
        last.assign(26, -1);

        dfs(0, s, parent);

        return res;
        
    }
};