#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
    vector<vector<int>> M (N, vector<int> (N));
    rep(i, 0, N){
        rep(j, 0, N){
            cin >> M[i][j];
        }
    }
    vector<int> dp (1 << N);
    dp[0] = 1;

    rep(j, 0, (1 << N)){
        int b = __builtin_popcount(j) - 1;
        rep(k, 0, N){
            if ((1 << k) & j and M[k][b]){
                dp[j] += dp[j ^ (1 << k)]; dp[j] %= MOD;
            }
        }
    }
    cout << dp[(1 << N) - 1] << '\n';
    return 0;
}
