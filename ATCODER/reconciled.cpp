#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i {ini}; i < x; ++i)
#define per(i, fin, x) for (int i {fin}; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>
#define MOD sci(1e9 + 7)

int main()
{
    UNSYNC
    i64 N, M; cin >> N >> M;
    if (N > M) swap(N, M);
    if (M - N > 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    i64 ans = 1;
    rep(i, 0, M) ans = (ans*(i + 1)) % MOD;
    rep(i, 0, N) ans = (ans*(i + 1)) % MOD;
    if (M - N == 0) ans = (ans*2) % MOD;
    cout << ans << '\n';
    return 0;
}
