#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

const i64 MOD = 1e9 + 7;
int main()
{
    UNSYNC
    i64 N, K; cin >> N >> K;
    VI A (N); rep(i, 0, N) cin >> A[i];
    i64 ans = 0;
    rep(i, 0, N){
        rep(j, 0, N){
            if (A[i] <= A[j]) continue;
            ans += K * (K - 1) / 2;
            if (i < j) ans += K;
            ans %= MOD;
        }
    }
    cout << ans << '\n';
    return 0;
}
