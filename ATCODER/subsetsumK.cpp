#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

const int MOD = 998244353;
int main()
{
    UNSYNC
    int N, K; cin >> N >> K;
    vector<int> dp (K + 1);
    dp[0] = 1;
    rep(i, 0, N){
        string s; int x;
        cin >> s >> x;
        if (s == "+"){
            per(j, K, x) dp[j] = (dp[j] + dp[j - x]) % MOD;
        } else {
            rep(j, x, K + 1) dp[j] = (dp[j] - dp[j - x] + MOD) % MOD;
        }
        cout << dp[K] << '\n';
    }
    return 0;
}
