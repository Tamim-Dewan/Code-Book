const int N = 200005;
const int LOG = 20;

int n; cin >> n;

vector<vector<int>> adj(n + 1);
vector<vector<int>> up(n + 1, vector<int>(LOG));
vector<int> depth(n + 1, 0);

for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// DFS to fill up[] and depth[]
function<void(int,int)> dfs = [&](int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < LOG; i++) {
        up[u][i] = up[ up[u][i-1] ][i-1];
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
};

int root = 1;
dfs(root, root);

// Lift node u by k steps
auto lift = [&](int u, int k) {
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            u = up[u][i];
        }
    }
    return u;
};

// Find LCA of u and v
function<int(int,int)> lca = [&](int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    u = lift(u, depth[u] - depth[v]);
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
};

// Distance between u and v
auto dist = [&](int u, int v) {
    int L = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[L];
};

// Find k-th node on path from u to v (0-based, u is 0-th)
auto kth_node_on_path = [&](int u, int v, int k) {
    int L = lca(u, v);
    int du = depth[u] - depth[L];
    if (k <= du) {
        return lift(u, k);
    } else {
        int dv = depth[v] - depth[L];
        return lift(v, du + dv - k);
    }
};

// Usage examples:
// int x = lca(u, v);
// int d = dist(u, v);
// int kth_node = lift(u, k);
// int ans = kth_node_on_path(u, v, k);
// u is ancestor of v if lca(u, v) == u