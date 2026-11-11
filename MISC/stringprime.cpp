#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int lim = 1000001;
void solve() {
    vector<int> primes (lim, 1);
    primes[0] = primes[1] = 0;
    auto sieve = [&] () {
        for (int i = 2; i < lim; ++i) {
            if (!primes[i]) continue;
            for (i64 j = 1LL * i * i; j < lim; j += i){
                primes[j] = 0;
            }
        }
    };
    sieve();

    string s; cin >> s;
    int n = s.size();
    vector<int> dp (n + 1); //number of prime divisions using first i digits only
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i + j <= n) {
                int p = stoi(s.substr(i, j));
                if (primes[p]) dp[i + j] += dp[i];
            }
        }
    }
    cout << dp[n] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
