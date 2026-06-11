// const int MAXN = 2e6 + 10;

// vector<bool> is_Prime(MAXN, true);
// vector<int> divs[MAXN];
// int spf[MAXN]; // Smallest Prime Factor

// void sieve()
// {
//     is_Prime[0] = is_Prime[1] = false;

//     for (int i = 2; i < MAXN; ++i)
//     {
//         if (is_Prime[i])
//         {
//             for (int j = i * i; j < MAXN; j += i)
//             {
//                 is_Prime[j] = false;
//                 if (spf[j] == 0)
//                     spf[j] = i;
//             }
//         }
//     }
// }

// void divisors()
// {
//     for (int i = 1; i < MAXN; ++i)
//         for (int j = i; j < MAXN; j += i)
//             divs[j].push_back(i);
// }

// vector<int> prime_factors(int n)
// {
//     vll ans;
//     while (n > 1)
//     {
//         int _lp = spf[n];
//         if (is_Prime[n])
//         {
//             ans.pb(n);
//             break;
//         }
//         while (n % _lp == 0)
//         {
//             n /= _lp;
//             ans.pb(_lp);
//         }
//     }

//     return ans;
// }