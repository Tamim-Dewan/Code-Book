
/*
DSU dsu(n);  // for n elements (1-indexed)
int root = dsu.find(x);//epresentative (root) of x
Check if Two Elements Are in the Same Component
if (dsu.same(x, y)) { // x and y are connected}
dsu.merge(x, y);  // merges components of x and y, if different
int size = dsu.get_size(x);  // returns size of component containing x
dsu.count();  // number of disjoint sets/connectec components
*/
struct DSU
{
    vector<int> par, rnk, _sz; int c;
    DSU(int n) : par(n + 1), rnk(n + 1, 0), _sz(n + 1, 1), c(n) {
        for (int i = 1; i <= n; ++i) par[i] = i;
    }
    int find(int i) {return (par[i] == i ? i : (par[i] = find(par[i])));}
    bool same(int i, int j) { return find(i) == find(j);}
    int get_size(int i) { return _sz[find(i)];}
    int count() { return c;}
    int merge(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return -1;
        else --c;
        if (rnk[i] > rnk[j]) swap(i, j);
        par[i] = j; _sz[j] += _sz[i];
        if (rnk[i] == rnk[j]) rnk[j]++;
        return j;
    }
};