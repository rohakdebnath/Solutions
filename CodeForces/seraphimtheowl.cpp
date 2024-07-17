#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve() {
    int N, M; cin >> N >> M;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    vector<int> B (N); rep(i, 0, N) cin >> B[i];

    vector<int> dp (N); 
    int m = 0;
    per(i, N - 1, 0){
        dp[i] = A[i] + m;
        m += min(A[i], B[i]);
    }
    cout << *min_element(dp.begin(), dp.begin() + M) << '\n';
}

signed main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
