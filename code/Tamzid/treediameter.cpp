ll num,ans;
vector<vector<ll>>adj;
vector<bool>visited;
ll find_diameter(ll node){
    visited[node]=1;
    multiset<ll>ms;ms.insert(0);
    for(auto it:adj[node]){
        if(!visited[it]){
            ms.insert(find_diameter(it));}}
    auto it=ms.rbegin();
    ll maxi=*it;it--;
    ll second=*it;
    ans=max(ans,maxi+second);
    return maxi+1;}

