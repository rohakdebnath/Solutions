#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

const i64 MOD = 1e9 + 7;
const i64 MAX = 1e6 + 1;
int main()
{
    UNSYNC
    i64 N, X; cin >> N >> X;
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    i64* dp = (i64*)calloc(MAX, sizeof(i64));
    dp[0] = 1;
    rep(i, 0, N){
        rep(j, 1, MAX){
            if (j - A[i] >= 0) dp[j] += dp[j - A[i]], dp[j] %= MOD;
        }
    }
    cout << dp[X] << '\n';
    free(dp);
    return 0;
}
