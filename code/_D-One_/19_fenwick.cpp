// A[] has to be 1-indexed
// create BIT of n elements : BIT<ll> bit(n);
// MODE A (point-update + prefix/range-sum):
// add v to A[idx]: bit.upd(idx, v);
// sum of A[1..idx]: ll sum1 = bit.query(idx);
// sum of A[l..r]: ll sumLR = bit.query(l, r);
// MODE B (range-update + point-query):
// add v to every A[i] for i in [l..r]: bit.upd(l, r, v);
// current A[idx]: ll Ai = bit.query(idx);
// Note: Do NOT mix MODE A and MODE B on the same instance
 
template <class T> struct BIT{
    int n; vector<T> t;
    BIT() : n(0) {}
    BIT(int _n) { n = _n; t.assign(n + 1, 0); }
    static int lowbit(int x) { return x & -x; }
    T query(int i) const {
        T ans = 0;
        for (; i > 0; i -= lowbit(i))
            ans += t[i];
        return ans;
    }
    void add(int i, T val) {
        if (i <= 0) return;
        for (; i <= n; i += lowbit(i))
            t[i] += val;
    }
    T query(int l, int r) const {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
    void add(int l, int r, T val) {
        add(l, val); add(r + 1, -val);
    }
};