void solve(){
    ll n,m;
    cin>>n>>m;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    loop(i,0,m){
        ll u,v,wt;cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});}
    ll totalcost=0;ll count=0;
    pq.push({0,1});
    while(!pq.empty() && count<n){
        auto [cost,node]=pq.top();
        pq.pop();
        if(vis[node]) continue;
        vis[node]=true;totalcost+=cost;
        count++;
        for(auto [child,wt]:graph[node]){
            if(vis[child]) continue;
            pq.push({wt,child});}}
    if(count==n) cout<<totalcost<<endl;
    else cout<<"IMPOSSIBLE\n";}
