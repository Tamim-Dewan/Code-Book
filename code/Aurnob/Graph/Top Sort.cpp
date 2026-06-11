/**
 * TOPOLOGICAL SORT (Kahn's Algorithm - BFS)
 * TIME COMPLEXITY: O(V + E)
 * SPACE COMPLEXITY: O(V + E)
 * USE CASE: Order tasks with dependencies. Detect cycles in directed graphs.
 * INPUT: n (nodes, 1-indexed here), adj (adjacency list)
 * OUTPUT: Vector with order. If output size != n, a CYCLE exists!
 **/
vector<int> topoSort(int n, const vector<vector<int>>& adj) {
    vector<int> in_degree(n + 1, 0);
    // Step 1: Calculate in-degrees
    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
        in_degree[v]++;}}
    // Step 2: Push all nodes with 0 in-degree to queue
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
        q.push(i);}}
    // Step 3: Process nodes
    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
        in_degree[v]--;
        if (in_degree[v] == 0) {
        q.push(v);}}}
    // Step 4: Cycle Check
    if (order.size() != n) {
        return {}; // Returns empty vector if a cycle exists (impossible to sort)
    }
    return order;}