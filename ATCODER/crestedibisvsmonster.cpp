#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

int main()
{
    UNSYNC
    i64 H, N; cin >> H >> N;
    vector<i64> A (N), B (N); rep(i, 0, N) cin >> A[i] >> B[i];
    vector<i64> dp (H + *max_element(all(A)), INT32_MAX); //dp[i] is the minimum pts that is needed to deal i damage
    dp[0] = 0;

    int m = *max_element(all(A));
    rep(j, 0, N){
        rep(i, 0, H + m){
            if (i - A[j] >= 0) dp[i] = min(dp[i], dp[i - A[j]] + B[j]);
        }
    }
    i64 ans = INT32_MAX;
    rep(i, H, H + m){
        ans = min((ans), dp[i]);
    }
    cout << ans << '\n';
    return 0;
}
