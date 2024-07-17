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
    sort(all(preidx), [&] (i64 i, i64 j) {return a[i] < a[j];});
    sort(all(a));
    
    VI vans (n);
    i64 j = 0;
    i64 cursum = 0;
    rep(i, 0, n){
        if (i == j) cursum += a[i], ++j;
        while (cursum >= a[j] and j < n){
            cursum += a[j];
            ++j;
        }
        vans[preidx[i]] = j - 1;
    }
    for(i64 x: vans) cout << x << ' ';
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
