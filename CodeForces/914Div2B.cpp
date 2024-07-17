#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

void solve()
{
    i64 n; cin >> n;
    VI a (n); rep(i, 0 ,n) cin >> a[i];
    VI preidx (n);
    iota(all(preidx), 0);
    sort(all(preidx), [&] (int i, int j) {return a[i] < a[j];});
    VI idx (n);
    rep(i, 0, n) idx[preidx[i]] = i;

    sort(all(a));
    VI ps (n); ps[0] = a[0];
    rep(i, 1, n) ps[i] = ps[i - 1] + a[i];
    VI vans (n); vans[n - 1] = n - 1;
    per(i, n - 2, 0)
    {
        if (ps[i] >= a[i + 1]) vans[i] = vans[i + 1];
        else vans[i] = i;
    }
    for (int i: idx) cout << vans[i] << ' ';
    cout << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
