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
    vector<int> dp (N + 1);
    dp[0] = 1;
    rep(i, 1, N + 1){
        rep(j, 1, 7){
            if (i >= j) dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    cout << dp[N] << '\n';
    return 0;
}
