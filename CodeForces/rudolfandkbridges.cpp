#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve()
{
    i64 n, m, k, d; cin >> n >> m >> k >> d;
    vector<i64> ans (n);
    rep(i, 0, n){
        vector<i64> A (m); rep(j, 0, m) cin >> A[j];
        multiset<i64> lastd; lastd.insert(A[0] + 1);
        vector<i64> t (m); t[0] = 1;
        rep(j, 1, m){
            t[j] = A[j] + 1 + *lastd.begin();
            lastd.insert(t[j]);
            if (int(lastd.size()) == d + 2){
                lastd.erase(lastd.find(t[j - d - 1]));
            }
        }
        ans[i] = t[m - 1];
    }

    vector<i64> pfA (n); partial_sum(all(ans), pfA.begin());
    i64 fin = INT64_MAX;
    rep(i, k - 1, n){
        fin = min(fin, pfA[i] - (i < k ? 0 : pfA[i - k]));
    }
    cout << fin << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
