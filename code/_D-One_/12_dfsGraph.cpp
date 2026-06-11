int n, m; cin >> n >> m;
vector<vector<int>> adj(n + 1);
vector<int> vis(n + 1, 0);
for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v])
            dfs(v);
    }
};
for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
        dfs(i);
    }
}