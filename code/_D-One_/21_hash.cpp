#define MOD1 999119999
#define MOD2 999999733
#define BASE1 313
#define BASE2 317

struct Hasher64 {
    int n;
    vector<uint32_t> pref1, pref2, pow1, pow2;
    Hasher64() {}
    Hasher64(const vector<int>& s) {
        n = s.size();
        pref1.assign(n + 1, 0);
        pref2.assign(n + 1, 0);
        pow1.assign(n + 1, 0);
        pow2.assign(n + 1, 0);
        pow1[0] = pow2[0] = 1;
        for (int i = 1; i <= n; i++) {
            uint32_t val = s[i - 1] + 1;
            pref1[i] = (val + (uint64_t)BASE1 * pref1[i - 1]) % MOD1;
            pref2[i] = (val + (uint64_t)BASE2 * pref2[i - 1]) % MOD2;
            pow1[i] = (uint64_t)pow1[i - 1] * BASE1 % MOD1;
            pow2[i] = (uint64_t)pow2[i - 1] * BASE2 % MOD2;
        }
    }

    inline uint64_t getHash(int l, int r) {
        uint32_t h1 = (pref1[r + 1] -
                       (uint64_t)pref1[l] * pow1[r - l + 1] % MOD1 + MOD1) %
                      MOD1;
        uint32_t h2 = (pref2[r + 1] -
                       (uint64_t)pref2[l] * pow2[r - l + 1] % MOD2 + MOD2) %
                      MOD2;
        return (uint64_t(h2) << 32) | h1;
    }
};

// ================= HOW TO USE =================
// vector<int> v(n);
// for strings:
// for(char c : s) v.push_back(c);
// Hasher64 H(v);
// auto h = H.getHash(l,r);// hash value
// pass 0-based index not value
// if(H.getHash(l1,r1) == H.getHash(l2,r2)) // compare
// Query: O(1) // Build: O(n)