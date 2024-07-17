#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

const i64 MOD = 998244353;
int main()
{
    UNSYNC
    i64 N, M; cin >> N >> M;
    i64 ans = 0;
    rep(i, 0, 62){
        if ((M & (1LL << i)) == 0) continue;
        ans += ((N + 1) / (1LL << i) / 2LL) * (1LL << i) + ((N + 1) / (1LL << i) % 2 ? (N + 1) % (1LL << i) : 0);
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}
