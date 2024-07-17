#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

void solve()
{
    int n, k; cin >> n >> k;
    VI a (n), b (n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    rep(i, 1, n) b[i] = max(b[i], b[i - 1]);
    rep(i, 1, n) a[i] += a[i - 1];
    int maxi = 0;
    rep(i, 0, min(n, k))
    {
        maxi = max(maxi, a[i] + (k - i - 1)*b[i]);
    }
    cout << maxi << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
