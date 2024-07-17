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

int main()
{
    UNSYNC
    i64 n, m; cin >> n >> m;
    VI girlmax (m), boymin(n);
    rep(i, 0, n) cin >> boymin[i];
    rep(i, 0, m) cin >> girlmax[i];

    sort(all(girlmax));
    sort(all(boymin), greater<i64> ());

    if (girlmax[0] < boymin[0]){
        cout << "-1\n";
        return 0;
    }
    if (girlmax[0] == boymin[0]){
        cout << accumulate(all(girlmax), 0LL) + m*(accumulate(1 + all(boymin), 0LL)) << '\n';
        return 0;
    }
    if (n == 1){
        cout << "-1\n";
        return 0;
    }

    cout << accumulate(all(girlmax), 0LL) + boymin[0] + boymin[1]*(m - 1) + m*(accumulate(2 + all(boymin), 0LL)) << '\n';
    return 0;
}
