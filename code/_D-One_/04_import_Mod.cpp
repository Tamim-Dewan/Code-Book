int powerM(int a, int b, int m) {a %= m;int res = 1;while (b > 0) {if (b & 1)res = res * a % m;a = a * a % m;b >>= 1;}return res;}//log(n)

ll inv(ll a){return powerM(a, mod - 2, mod);}

int plusM(int a, int b){return ((a % mod) + (b % mod)) % mod;}
int intoM(int a, int b){return ((a % mod) * (b % mod)) % mod;}
int minusM(int a, int b){return ((a % mod) - (b % mod) + mod) % mod;}
int divideM(int a, int b){return ((a % mod) * inv(b) % mod) % mod;}
