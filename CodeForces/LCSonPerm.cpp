#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

const i64 MOD = 1e9;
int main()
{
    UNSYNC
    i64 N; cin >> N;
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    vector<i64> B (N); rep(i, 0, N) cin >> B[i];

    vector<int> pos (N + 1);
    rep(i, 0, N){
        pos[A[i]] = i;
    }
    vector<int> nA (N);
    rep(i, 0, N){
        nA[i] = pos[B[i]];
    }
    
    vector<i64> dp (N + 1, MOD); dp[0] = - MOD;
    rep(i, 0, N){
        i64 l = upper_bound(all(dp), nA[i]) - dp.begin();
        dp[l] = nA[i];
    }
    i64 ans = 0;
    rep(i, 0, N + 1){
        if (dp[i] < MOD) ans = i;
    }
    cout << ans << '\n';
    return 0;
}
