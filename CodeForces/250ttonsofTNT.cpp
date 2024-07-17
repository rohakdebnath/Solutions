#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

void solve()
{
    int N; cin >> N;
    VI A (N); rep(i, 0, N) cin >> A[i];
    VI pfA (N + 1); partial_sum(all(A), pfA.begin() + 1);

    i64 ans = 0;
    rep(i, 1, N){
        if (N % i != 0) continue;
        i64 mini = INT64_MAX;
        i64 maxi = 0;
        rep(j, 1, N/i + 1){
            mini = min(mini, pfA[i*j] - pfA[i*(j - 1)]);
            maxi = max(maxi, pfA[i*j] - pfA[i*(j - 1)]);
        }
        ans = max(ans, maxi - mini);
    }
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
