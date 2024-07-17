#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int x, y; cin >> x >> y;
    int ans = y > 0 ? (y - 1) / 2 + 1 : 0;
    int rem = ans * 15 - y * 4;
    if (x > rem){
        ans += (x - rem - 1) / 15 + 1;
    }
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
