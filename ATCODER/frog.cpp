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
    vector<int> A (N); rep(i, 0, N) cin >> A[i];

    i64 dp[100000];
    dp[0] = 0;
    dp[1] = abs(A[1] - A[0]);
    rep(i, 2, N){
        dp[i] = min(dp[i - 1] + abs(A[i] - A[i - 1]), dp[i - 2] + abs(A[i] - A[i - 2]));
    }
    cout << dp[N - 1] << '\n';
    return 0;
}
