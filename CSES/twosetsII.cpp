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
    i64 N; cin >> N;
    i64 sum = N * (N + 1) / 2;
    if (sum & 1){
        cout << "0\n";
    } else {
        i64 targ = sum / 2;
        vector<vector<i64>> dp (N + 1, vector<i64> (targ + 1));
        dp[0][0] = 1;
        rep(i, 1, N){
            rep(j, 0, targ + 1){
                dp[i][j] = dp[i - 1][j];
                if (j - i >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
            }
        }
        cout << dp[N - 1][targ] << '\n';
    }
    return 0;
}
// #include <bits/stdc++.h>
 
// using namespace std;
// using i64 = long long;
 
// #define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
// #define all(x) x.begin(), x.end()
// #define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
// #define per(i, fin, x) for (i64 i = fin; i >= x; --i)
 
// const i64 MOD = 1e9 + 7;
// int main()
// {
//     UNSYNC
//     i64 N; cin >> N;
//     i64 sum = N * (N + 1) / 2;
//     if (sum & 1){
//         cout << "0\n";
//     } else {
//         i64 targ = sum / 2;
//         vector<i64> dp (targ + 1);
//         dp[0] = 1;
//         rep(i, 1, N + 1){
//             per(j, targ - i, 0){
//                 if (dp[j]) dp[j + i] = (dp[j + i] + dp[j]) % MOD;
//             }
//         }
//         i64 ans = (dp[targ] * 500000004) % MOD;
//         cout << ans << '\n';
//     }
//     return 0;
// }
