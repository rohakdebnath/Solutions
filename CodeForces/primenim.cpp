#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e6;
vector<int> g (inf + 1);
vector<int> lowestfactor (inf + 1);
vector<int> primes;
void solve() {
    int n; cin >> n;
    cout << (g[n] > 0 ? "Alice\n": "Bob\n");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (int i = 1; i <= inf; ++i) lowestfactor[i] = i;
    for (int i = 2; i <= inf; ++i) {
        for (int j = 2 * i; j <= inf; j += i) {
            if (lowestfactor[j] != j) continue;
            lowestfactor[j] = i;
        }
    }
    for (int i = 2; i <= inf; ++i) {
        if (lowestfactor[i] == i) primes.push_back(i);
    }
    cout << primes.size() << '\n';
    // for (int i = 2; i <= inf; ++i) {
    //     map<int, int> s;
    //     for (int p: primes) {
    //         if (i - p >= 0) s[g[i - p]] = 1;
    //     }
    //     int mex = 0;
    //     while (s[mex]) ++mex;
    //     g[i] = mex;
    // }
    // int t; cin >> t;
    // while (t--) solve();
    return 0;
}
