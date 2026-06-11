ll segtree[N*4];
ll a[N];
ll func(ll a,ll b){
    return min(a,b);}

void build_segtree(ll node, ll lo, ll hi){
    if(lo==hi){
        segtree[node]=a[lo];
        return;}
    ll mid=(lo+hi)/2;
    build_segtree(node*2,lo,mid);
    build_segtree((node*2)+1,mid+1,hi);
    segtree[node]=func(segtree[node*2],segtree[(node*2)+1]);}

ll query(ll node, ll lo, ll hi, ll l, ll r){
    if(r<lo || l>hi){
        return INF;}
    if(l<=lo && r>=hi){
        return segtree[node];}
    ll mid=(lo+hi)/2;
    ll left=query(node*2,lo,mid,l,r);
    ll right=query((node*2)+1,mid+1,hi,l,r);
    return func(left,right);}

void update(ll node, ll lo, ll hi, ll pos, ll u){
    if(lo==hi){
        segtree[node]=u;
        return;}
    ll mid=(lo+hi)/2;
    if(pos<=mid){
        update(node*2,lo,mid,pos,u);
    }else{
        update(node*2+1,mid+1,hi,pos,u);}
    segtree[node]=func(segtree[node*2],segtree[node*2+1]);}


int main(){
    ll n,q;
    cin>>n>>q;
    loop(i,1,n+1){
        cin>>a[i];}
    build_segtree(1,1,n);
    loop(i,0,q){
        ll inp,l,r;
        cin>>inp>>l>>r;
        if(!(inp&1)){
            cout<<query(1,1,n,l,r)<<endl;
        }else{
            update(1,1,n,l,r);
        }}}