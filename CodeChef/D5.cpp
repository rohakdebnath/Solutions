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

const i64 MOD = 998244353;
void solve()
{
    i64 N, M; cin >> N >> M;
    if (N < M) swap(N, M); //N >= M wlog
    i64 ans1 = (N & 1 ? N/2 + 1: N/2 + N/2 + 1);

    i64 left = max(1LL, M - N/2), right = min(M, 1 + N/2);
    i64 ans2 = ((right*(right + 1))/2 - ((left - 1)*(left))/2) % MOD;
    
    i64 ans = ((ans1)*(ans2)) % MOD;
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
