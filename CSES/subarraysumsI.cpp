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
    i64 n, x; cin >> n >> x;
    VI a (n); rep(i, 0, n) cin >> a[i];

    i64 ans = 0;
    i64 sum = 0;
    i64 j = 0;
    rep(i, 0, n){
        while (a[j] + sum <= x and j < n) sum += a[j++];
        ans += sum == x;
        sum -= a[i];
    }
    cout << ans << '\n';
    return 0;
}
