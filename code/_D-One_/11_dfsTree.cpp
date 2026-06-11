int n; cin >> n;
vector<vector<int>> adj(n + 10);
for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
// vector<int> lvl(n + 10);        
// vector<int> h(n + 10);          
// vector<int> stree(n + 10, 1);   
function<void(int, int)> dfs = [&](int u, int p) -> void {
    // lvl[u] = lvl[p] + 1; // If root is 0-indexed, set lvl[0] = -1
    for (int v : adj[u]) {
        if (v == p) continue;
        // lvl[v] = lvl[u] + 1;
        dfs(v, u);
        // h[u] = max(h[u], h[v] + 1);
        // stree[u] += stree[v];
    }
};

dfs(1, 0); // root = 1