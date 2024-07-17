#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    int ans = 0;
    int j = 0;
    rep(i, 0, n){
        while(b[j] != a[i] and j < m) ++j;
        if (j < m) ++ans, ++j;
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
