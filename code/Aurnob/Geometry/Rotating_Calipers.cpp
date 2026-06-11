// cross(o, a, b) = (a - o) X (b - o)
ll cross(const point &o, const point &a, const point &b) {
    return (a.x - o.x) * (b.y - o.y)
         - (a.y - o.y) * (b.x - o.x);}
// Rotating calipers to find max squared distance on convex polygon H
ll max_pair_dist2(const vector<point>& H) {
    int m = H.size();
    if (m < 2) return 0;
    if (m == 2) return DIST2(H[0], H[1]);
    ll best = 0;int j = 1;
    for (int i = 0; i < m; ++i) {
        while (abs(cross(H[i], H[(i+1)%m], H[(j+1)%m]))
             > abs(cross(H[i], H[(i+1)%m], H[j]))){
            j = (j+1) % m;}
        best = max(best, (ll)DIST2(H[i], H[j]));
        best = max(best, (ll)DIST2(H[(i+1)%m], H[j]));}
    return best;}
