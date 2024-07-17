#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve()
{
    i64 M, X; cin >> M >> X;
    vector<i64> dp {0}; //dp[i] is the max money left after buying i happiness
    i64 s = 0;
    rep(i, 0, M){
        i64 c, h; cin >> c >> h;
        s += h;
        dp.resize(s + 1, -1);
        per(j, s, h){
            dp[j] = max(dp[j], dp[j - h] - c);
        }
        rep(j, 0, s + 1) if (dp[j] >= 0) dp[j] += X;
    }
    i64 ans = 0;
    rep(i, 0, s + 1) if (dp[i] >= 0) ans = i;
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
