#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    int N; cin >> N;
    vector<int> dp (N + 1, INT32_MAX);
    dp[0] = 0;
    for (int j: {6, 9}){
        rep(i, 1, N + 1){
            dp[i] = min(dp[i], dp[i - 1] + 1);
            int t = j;
            while (t <= i){
                dp[i] = min(dp[i], dp[i - t] + 1);
                t *= j;
            }
        }
    }
    cout << dp[N] << '\n';
    return 0;
}
