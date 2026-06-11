//Your task is to maintain a list of arrays which initially has 
//a single array. You have to process the following types of queries:
//1.Set the value a in array k to x.
//2.Calculate the sum of values in range [a,b] in array k.
//3.Create a copy of array k and add it to the end of the list.
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef vector<ll> vll;
const int MX = 1e6 + 9; 
int root[MX];
struct Node{
    int left = 0;
    int right = 0;
    ll val = 0;};
Node nodes[MX * 40];
struct PerSegTree{
int id = 0;
int build(vll &a, int lx, int rx){
    int cur = ++id;
    if (lx == rx){
        nodes[cur].val = a[lx];
        return cur;}
    int mid = (lx + rx) / 2;
    nodes[cur].left = build(a, lx, mid);
    nodes[cur].right = build(a, mid + 1, rx);
    nodes[cur].val = nodes[nodes[cur].left].val + nodes[nodes[cur].right].val;
    return cur;}
int update(int prev, int i, ll v, int lx, int rx){
    int cur = ++id;
    nodes[cur] = nodes[prev];
    if (lx == rx){
        nodes[cur].val = v;
        return cur;}
    int mid = (lx + rx) / 2;
    if (i <= mid) 
        nodes[cur].left = update(nodes[cur].left, i, v, lx, mid);
    else
        nodes[cur].right = update(nodes[cur].right, i, v, mid + 1, rx);
        nodes[cur].val = nodes[nodes[cur].left].val + nodes[nodes[cur].right].val;
        return cur;}

ll getSum(int cur, int l, int r, int lx, int rx){
    if (rx < l || r < lx){
        return 0;}
    if (lx >= l && rx <= r){
        return nodes[cur].val;
    }
    int mid = (lx + rx) / 2;
    return getSum(nodes[cur].left, l, r, lx, mid) + getSum(nodes[cur].right, l, r, mid + 1, rx);}
ll kth(int u, int v, int k, int lx, int rx, vector<ll> &sortedA){//0 based
    if(lx == rx) return sortedA[lx];
    int mid = (lx + rx) / 2;
    int cnt = nodes[nodes[v].left].val - nodes[nodes[u].left].val;
    if(k <= cnt) 
        return kth(nodes[u].left, nodes[v].left, k, lx, mid, sortedA);
    else
        return kth(nodes[u].right, nodes[v].right, k - cnt, mid + 1, rx, sortedA);}};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vll a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    PerSegTree tree;
    int version_count = 1;
    root[version_count] = tree.build(a, 1, n);
    while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
        int k, idx; ll x;
        cin >> k >> idx >> x;
        // Update array k directly
        root[k] = tree.update(root[k], idx, x, 1, n);
    } 
    else if (type == 2) {
        int k, l, r;
        cin >> k >> l >> r;
        // Query array k
        cout << tree.getSum(root[k], l, r, 1, n) << "\n";
    } 
    else if (type == 3) {
        int k;
        cin >> k;
        // Create a new copy referencing array k's current state
        version_count++;
        root[version_count] = root[k];
    }
    }
    return 0;
}