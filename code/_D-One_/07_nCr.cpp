const int MAX = 2e5 + 10;
int fact[MAX], iFact[MAX];
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) fact[i] = (fact[i - 1] * i) % mod;

    iFact[MAX - 1] = powerM(fact[MAX - 1], mod - 2, mod);
    for (int i = MAX - 2; i >= 0; i--) iFact[i] = (iFact[i + 1] * (i + 1)) % mod;
}
//O(1)
int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * iFact[r]) % mod) * iFact[n - r]) % mod;
}