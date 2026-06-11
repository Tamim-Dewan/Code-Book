struct node
{
    int mini, cnt;
    node(int m = INF, int c = 1) {
        mini = m, cnt = c;
    }
};

struct SegTree
{
    int n;
    vector<node> tree;
    void init(int sz) { n = sz; tree.assign(4 * n, node());}

    node merge(node a, node b){
        if (a.mini < b.mini) return a;
        else if (b.mini < a.mini) return b;
        else {
            node tmp(a.mini, a.cnt + b.cnt);
            return tmp;
        }
    }

    void build(vector<int> &a, int v, int tl, int tr){
        if (tl == tr){tree[v] = node(a[tl], 1);}
        else{
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    void build(vector<int> &a) {build(a, 1, 0, n - 1);}

    node query(int v, int tl, int tr, int l, int r){
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        if (r <= tm) return query(v * 2, tl, tm, l, r);
        if (l > tm) return query(v * 2 + 1, tm + 1, tr, l, r);
        node left = query(v * 2, tl, tm, l, tm);
        node right = query(v * 2 + 1, tm + 1, tr, tm + 1, r);
        return merge(left, right);
    }
    node query(int l, int r) { return query(1, 0, n - 1, l, r); }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            tree[v] = node(new_val, 1);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(v * 2, tl, tm, pos, new_val);
            else update(v * 2 + 1, tm + 1, tr, pos, new_val);
            tree[v] = merge(tree[v * 2], tree[v * 2 + 1]); 
        }
    }
    void update(int pos, int new_val){update(1, 0, n - 1, pos, new_val);}
};

// template এ সব 0-based
// a[0] to a[n-1] → original array for build
// tree[1] → whole segment [0..n-1]
// tree[v] → covers segment [tl..tr]
// [l, r] = range you want to query
// [tl, tr] = segment of current node

// Usage:
// SegTree st;
// st.init(n);
// st.build(a);
