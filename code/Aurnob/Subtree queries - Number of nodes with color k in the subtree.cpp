const ll INF=1e16;
const double EPS = 1e-9;
const ll M=1e9+7;
const ll N=1e5+5;
set<ll> collec[N];
vector<ll> ans(N,-1);
vector<ll> graph[N];
vector<ll> euler(N,-1);
vector<ll> subtree_size(N,-1);
vector<ll> position_in_euler(N,-1);
vector<ll> heavy_child(N,-1);
ll idx=0;
vector<map<ll,ll>> answers(N);
vector<pll> qs;
vector<ll> color(N,-1);
vll cnt(N);
void dfs(ll node,ll par,bool keep){
    for(auto child:graph[node]){
        if(child!=par && child!=heavy_child[node]){
            dfs(child,node,false);
        }
    }
    if(heavy_child[node]!=-1) dfs(heavy_child[node],node,true);
    cnt[color[node]]++;
    for(auto child:graph[node]){
        if(child!=par && child!=heavy_child[node]){
            for(int i=position_in_euler[child];i<position_in_euler[child]+subtree_size[child];i++){
                ll vertex=euler[i];
                cnt[color[vertex]]++;}}}
    for(auto &[a,b]:answers[node]){
        b=cnt[a];}
    if(!keep){
        for(int i=position_in_euler[node];i<position_in_euler[node]+subtree_size[node];i++){
            ll vertex=euler[i];
            cnt[color[vertex]]--;}}}

void solve(){
    ll n,q;cin>>n>>q;
    vector<ll> distinct_colors;
    for(ll i=1;i<=n;i++){
        cin>>color[i];
        distinct_colors.push_back(color[i]);}
    sort(all(distinct_colors));
    distinct_colors.erase(unique(all(distinct_colors)),distinct_colors.end());
    for(ll i=1;i<=n;i++){
        color[i]=lower_bound(all(distinct_colors),color[i])-distinct_colors.begin()+1;}
    loop(i,0,n-1){
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);}
    while(q--){
        ll a,b;
        cin>>a>>b; 
        ll realb=lower_bound(all(distinct_colors),b)-distinct_colors.begin()+1;;
        answers[a][realb]=-1;
        qs.push_back({a,realb});}
    dfs_plus(1,-1);
    dfs(1,-1,false);
    for(auto [a,b]:qs){
        cout<<answers[a][b]<<endl;}}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();}
