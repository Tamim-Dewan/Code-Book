int sum = 0, best = -1e18;
for(auto x : a){
    sum = max(x, sum + x);
    best = max(best, sum);
}
// best = max(best, 0LL); // allow empty subarray
