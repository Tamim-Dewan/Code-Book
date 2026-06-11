// vector<ll> primeFactors(int n){vll primes;while (n % 2 == 0){primes.pb(2);n = n / 2;}for (int i = 3; i <= sqrt(n); i = i + 2) {while (n % i == 0){primes.pb(i);n = n / i;}}if (n > 2)primes.pb(n);return primes;}
// bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
// bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}
// string bin(int n){string s;while(n > 0){s.push_back('0' + (n & 1));n >>= 1;}reverse(s.begin(), s.end());return s;}
// ll dec(const string& s) {return stoll(s, nullptr, 2);}
