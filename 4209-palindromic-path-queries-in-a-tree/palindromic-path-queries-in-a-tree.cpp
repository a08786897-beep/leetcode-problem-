class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    vector<int> tree;
    string node_str;
    int cur_pos;

    int dfs1(int u, int p, int d) {
        parent[u] = p;
        depth[u] = d;
        int size = 1, max_c_size = 0;
        heavy[u] = -1;
        for (int v : adj[u]) {
            if (v != p) {
                int sub_size = dfs1(v, u, d + 1);
                size += sub_size;
                if (sub_size > max_c_size) {
                    max_c_size = sub_size;
                    heavy[u] = v;
                }
            }
        }
        return size;
    }

    void dfs2(int u, int h) {
        head[u] = h;
        pos[u] = cur_pos++;
        if (heavy[u] != -1) {
            dfs2(heavy[u], h);
        }
        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                dfs2(v, v);
            }
        }
    }

    void update_tree(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update_tree(2 * node, l, mid, idx, val);
        } else {
            update_tree(2 * node + 1, mid + 1, r, idx, val);
        }
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    int query_tree(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = l + (r - l) / 2;
        return query_tree(2 * node, l, mid, ql, qr) ^ query_tree(2 * node + 1, mid + 1, r, ql, qr);
    }

    int query_path(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            res ^= query_tree(1, 0, n - 1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        res ^= query_tree(1, 0, n - 1, pos[u], pos[v]);
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        this->node_str = s;
        adj.assign(n, vector<int>());
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        parent.assign(n, 0);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        tree.assign(4 * n, 0);

        dfs1(0, -1, 0);
        cur_pos = 0;
        dfs2(0, 0);

        vector<int> initial_vals(n);
        for (int i = 0; i < n; ++i) {
            initial_vals[pos[i]] = (1 << (s[i] - 'a'));
        }

        auto build_arr = [&](auto& self, int node, int l, int r, const vector<int>& vals) -> void {
            if (l == r) {
                tree[node] = vals[l];
                return;
            }
            int mid = l + (r - l) / 2;
            self(self, 2 * node, l, mid, vals);
            self(self, 2 * node + 1, mid + 1, r, vals);
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        };
        build_arr(build_arr, 1, 0, n - 1, initial_vals);

        vector<bool> ans;
        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                node_str[u] = c;
                int mask = (1 << (c - 'a'));
                update_tree(1, 0, n - 1, pos[u], mask);
            } else {
                int u, v;
                ss >> u >> v;
                int mask = query_path(u, v);
                bool is_palindrome = (mask == 0) || ((mask & (mask - 1)) == 0);
                ans.push_back(is_palindrome);
            }
        }
        return ans;
    }
};