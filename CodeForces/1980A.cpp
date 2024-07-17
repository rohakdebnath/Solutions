#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N, M; cin >> N >> M;
    string s; cin >> s;
    vector<int> f (26);
    rep(i, 0, N) ++f[s[i] - 'A'];
    int ans = 0;
    rep(i, 0, 7) ans += max(M - f[i], 0);
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
