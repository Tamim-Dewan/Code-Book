// 1-indexed array, like normal BIT.
// add(l, r, val) → range update
// sum(l, r) → range query
// BIT_RURQ<int> bit(n);
// bit.add(2, 5, 10);     
// cout << bit.sum(1, 4);

template <class T>
struct BIT_RURQ {
    int n; vector<T> t1, t2;
    BIT_RURQ() : n(0) {}
    BIT_RURQ(int _n) : n(_n), t1(n + 1, 0), t2(n + 1, 0) {}
    static int lb(int x) { return x & -x; }
    void upd(vector<T> &t, int i, T val) {
        for (; i <= n; i += lb(i)) t[i] += val;
    }
    T query(const vector<T> &t, int i) const {
        T res = 0;
        for (; i > 0; i -= lb(i)) res += t[i];
        return res;
    }
    void add(int l, int r, T val) {
        upd(t1, l, val); upd(t1, r + 1, -val);
        upd(t2, l, val * (l - 1)); upd(t2, r + 1, -val * r);
    }
    T prefix(int i) const {
        return i * query(t1, i) - query(t2, i);
    }
    T sum(int l, int r) const {
        return prefix(r) - prefix(l - 1);
    }
};