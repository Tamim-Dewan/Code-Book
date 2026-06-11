#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

/*=====================================================
GENERIC ORDERED SET "T" can be:
- int
- pair<int,int>
===================================================== */
template<typename T>
using ordered_set = tree< T, null_type, less<T>, rb_tree_tag, 
tree_order_statistics_node_update >;

// count elements strictly smaller than x
// s.order_of_key(x)

// get k-th smallest element (0-indexed)
// *s.find_by_order(k);

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ordered_set<int> s;

    return 0;
}