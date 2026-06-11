struct sparsetable
{
    vector<vector<ll>> lookup;
    vector<ll> arr;
    ll times = 1, siz;

    void initialize(ll num)
    {
        siz = num;
        arr.resize(num);
        times = log2(num);
        lookup.resize(num, vector<ll>(times + 1));
    }

    ll merge(ll val1, ll val2)
    {
        return min(val1,val2);
    }

    void build(vector<ll> &vec)
    {
        for (ll i = 0; i < siz; i++)
            lookup[i][0] = vec[i];

        for (ll j = 1; j <= times; j++)
        {
            for (ll i = 0; i + (1LL << j) <= siz; i++)
                lookup[i][j] = merge(lookup[i][j - 1], lookup[i + (1LL << (j - 1))][j - 1]);
        }
    }

    ll query(ll lo, ll hi)
    {
        ll j = log2(hi - lo + 1);
        return merge(lookup[lo][j], lookup[hi - (1LL << j) + 1][j]);
    }
};

// vector<ll> a = {5,3,8,1,7,4};
// sparsetable st;
// st.initialize(a.size());
// st.build(a);
// st.query(1, 3); // 0 baeds