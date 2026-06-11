ll num, edges;
vector<vector<ll>> adj, reverseadj;
vector<ll>visited,visitorder,ans;
vector<vector<ll>>allscc;

void dfs(ll node)
{
    visited[node]=1;
    for(auto it:adj[node])
    {
        if(!visited[it])dfs(it);
    }
    visitorder.push_back(node);
}

void dfs2(ll node,ll times)
{
    visited[node]=1;
    ans[node]=times;
    allscc[times-1].push_back(node);

    for(auto it:reverseadj[node])
    {
        if(!visited[it])
        dfs2(it,times);
    }
}

void kosaraju()
{
    for(ll i=0;i<num;i++)
    {
        if(!visited[i])dfs(i);
    }

    reverse(visitorder.begin(),visitorder.end());
    visited.assign(num,0);

    ll scc=0;
    for(auto i:visitorder)
    {
        if(!visited[i])
        {
            dfs2(i,++scc);
        }
    }

    cout<<scc<<endl;
    for(auto it:ans)cout<<it<<" ";

    for(ll i=0;i<scc;i++)
    {
        cout<<i<<": ";
        for(auto it:allscc[i])cout<<it<<" ";cout<<endl;
    }
}

