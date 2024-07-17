#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

const i64 MOD = 1e9 + 7;
int main()
{
    UNSYNC
    i64 N, M; cin >> N >> M;
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    vector<vector<i64>> dp (N, vector<i64> (M + 2));

    rep(i, 0, N){
        if (A[i]){
            if (i == 0) dp[0][A[0]] = 1;
            else dp[i][A[i]] = (dp[i - 1][A[i] - 1] + dp[i - 1][A[i]] + dp[i - 1][A[i] + 1]) % MOD;
            continue;
        }
        for (i64 j = 1; j <= M; j++){
            if (i == 0) dp[0][j] = 1;
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
        }
    }
    i64 ans = 0;
    rep(i, 1, M + 1){
        ans = (ans + dp[N - 1][i]) % MOD;
    }
    cout << ans << '\n';
    return 0;
}
 