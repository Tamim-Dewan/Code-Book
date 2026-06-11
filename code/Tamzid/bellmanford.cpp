struct Edge{
    ll from, to, cost;};
ll node, edges;         // no. of node and edges in the graph
vector<Edge> vec(200005); // store the edges from,to and cost.
vector<ll> dist(200005, INF);
vector<ll> par(200005, -1);
void Bellman_Ford(){
    dist[1] = 0;
    for (ll i = 1; i < node; i++){
        for (Edge it : vec){
        if (dist[it.from] < INF){
        if (dist[it.from] + it.cost < dist[it.to]){
        dist[it.to] = max(dist[it.from] + it.cost, -INF);
        par[it.to] = it.from;}}}}}
 
void retrieve_shortest_path(vector<ll> &path){
    if (dist[node] == INF) return; // NO Path Exist
    for (ll cur = node; cur != -1; cur = par[cur]){
    path.push_back(cur);}
    reverse(path.begin(), path.end());}
 
void find_negative_cycle(vector<ll> &path){
    // run this after bellman ford has been run
    ll start = -1;
    for (Edge it : vec){
        if (dist[it.from] < INF){
            if (dist[it.from] + it.cost < dist[it.to]){
            dist[it.to] = dist[it.from] + it.cost;
            start = it.to;
            par[it.to] = it.from;}}}
    if (start == -1)return; // no Negative cycle found so, path is empty
        for (ll times = 0; times < node; times++)
        start = par[start];
        path.push_back(start);
        for(ll cur=par[start];;cur=par[cur]){
            path.push_back(cur);
            if(cur==start)break;}
        reverse(path.begin(),path.end());}


