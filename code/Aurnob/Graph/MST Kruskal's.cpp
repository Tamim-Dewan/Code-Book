void solve(){
    ll n,m;cin>>n>>m;
    vector<pair<ll,pair<ll,ll>>> edges;
    loop(i,1,n+1) make_set(i);
    loop(i,0,m){
        ll u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});}
    ll ans=0;sort(edges.begin(),edges.end());
    loop(i,0,m){
        auto bruh=edges[i];
        ll u=bruh.second.first;
        ll v=bruh.second.second;
        ll wt=bruh.first;
        if(find_set(u)==find_set(v)){continue;}
        union_sets(u,v);ans+=wt;}
    set<ll> s;
    loop(i,1,n+1){s.insert(find_set(i));}
    if(s.size()!=1){
        cout<<"IMPOSSIBLE\n";return;}
    cout<<ans<<endl;}
