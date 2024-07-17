#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

const i64 inf = 1e18;

void solve()
{
    int N, K; cin >> N >> K;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    vector<vector<i64>> dp (N + 1, vector<i64> (K + 1, inf)); // dp[i][j] is the minimum sum achieved after doing j operations on the prefix of length i
    dp[0][0] = 0; //the idea is if we know the minimum sum for prefix i which has used only j operations, then lets say we want to use d more operations (all d st. d + j <= k) then we can say that dp[i + d + 1][j + d] = min of dp[i][j] + (d + 1) * (min element in range a[i + 1...d elements]) and itself. If we can build this, we will know that the best answer will be the smallest element of dp[N][0...K], (not directly dp[N][K] as sometimes all K operations are not necessary thus dp[N] may achieve minimum even with less than K moves)
    rep(i, 0, N){
        i64 m = A[i];
        for (int j = 0; j <= K and i + j < N; ++j){ //this is the extension 'd', obviously the extension should not make i cross N and also the extension itself is <= K
            m = min<i64>(m, A[i + j]);
            for (int k = 0; j + k <= K; ++k){ // this is the moves we have already made, so k + j <= K
                dp[i + j + 1][k + j] = min(dp[i + j + 1][k + j], dp[i][k] + (j + 1) * m); // dp[i][k] with j moves, operated on the next j + 1 elements, to make them all equal to the min element of those next j + 1 elements
            }
        }
    }
    cout << *min_element(all(dp[N])) << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
