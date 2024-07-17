#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

const int MOD = 1e9 + 7;
int main()
{
    UNSYNC
    int N; cin >> N;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    vector<int> dp (N + 1, MOD); dp[0] = -MOD;
    rep(i, 0, N){
        int l = upper_bound(all(dp), A[i]) - dp.begin();
        dp[l] = A[i];
    }
    int ans = 0;
    rep(i, 1, N + 1){
        if (dp[i] < MOD) ans = i;
    }
    cout << ans << '\n';
    return 0;
}
