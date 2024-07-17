#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    int n; cin >> n;
    VI a (n); rep(i, 0, n) cin >> a[i];
    sort(all(a));
    i64 med = a[n/2];
    i64 ans = accumulate(all(a), 0LL, [&] (i64 s, i64 i) {
        return s + abs (i - med);
    });
    cout << ans << '\n';
    return 0;
}
