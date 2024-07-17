#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
const int MOD = 1e9 + 7;
int main()
{
    UNSYNC
    i64 N, X; cin >> N >> X; 
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    i64 dp[1000001];
    dp[0] = 1;
    rep(i, 1, 1000001){
        dp[i] = 0;
        rep(j, 0, N){
            if (i - A[j] >= 0) dp[i] += dp[i - A[j]], dp[i] %= MOD;
        }
    }
    cout << dp[X] << '\n';
    return 0;
}
