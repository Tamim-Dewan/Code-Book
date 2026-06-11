struct ST {
  /* * PURPOSE: Segment Tree for Range Sum Query (RSQ) with Range Add Update.
   * * INDEXING: 
   * - 1-based indexing is recommended for consistency (indices 1 to n).
   * - 0-based is possible if you call build(1, 0, n-1), but 'a' array must match.
   * * USAGE EXAMPLES:
   * 1. DEFINITION & BUILD:
   * int n = 5; 
   * for(int i=1; i<=n; i++) a[i] = input[i]; // Fill global array 'a'
   * ST st(n);                                // Initialize vectors
   * st.build(1, 1, n);                       // Build tree from global array 'a'
   * * 2. UPDATE (Range Add):
   * // Add 10 to all elements in range [2, 4]
   * st.upd(1, 1, n, 2, 4, 10);
   * * 3. QUERY (Range Sum):
   * // Get sum of elements in range [2, 4]
   * ll result = st.query(1, 1, n, 2, 4);
   */
  #define lc (n << 1)
  #define rc ((n << 1) | 1)
  vector<ll> t, lazy;
  int N;
  ST(int n = 0) { init(n); }
  void init(int n) {
    N = n;
    t.assign(4 * (N + 5), 0);
    lazy.assign(4 * (N + 5), 0);
  }
  inline void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    // NOTE: Logic below is for SUM. 
    // For Min/Max, remove *(e-b+1) and just add lazy[n]
    t[n] += lazy[n] * (e - b + 1); 
    if (b != e) {
      lazy[lc] += lazy[n];
      lazy[rc] += lazy[n];
    }
    lazy[n] = 0;
  }
  inline void pull(int n) {
    t[n] = t[lc] + t[rc]; // NOTE: Change to max(t[lc], t[rc]) for RMQ
  }
  void build(int n, int b, int e) {
    lazy[n] = 0;
    if (b == e) { t[n] = a[b]; return; }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void upd(int n, int b, int e, int i, int j, ll v) {
    push(n, b, e);
    if (j < b || e < i) return;            
    if (i <= b && e <= j) {                 
      lazy[n] += v;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j, v);
    upd(rc, mid + 1, e, i, j, v);
    pull(n);
  }
  ll query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (j < b || e < i) return 0; // NOTE: Return infinity for Min, -infinity for Max
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) >> 1;
    return query(lc, b, mid, i, j) + query(rc, mid + 1, e, i, j);
  }
};