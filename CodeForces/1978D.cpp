#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve() {
    i64 N, C; cin >> N >> C;
    vector<i64> A (N); rep(i, 0, N) cin >> A[i]; A[0] += C;
    vector<i64> P (N + 1); partial_sum(all(A), P.begin() + 1);
    i64 c = max_element(all(A)) - A.begin();

    vector<i64> ans (N);
    rep(i, 0, N){
        if (c == i){
            ans[i] = 0;
            continue;
        }
        i64 x = A[i] + P[i];
        ans[i] = i + (x < A[c]);
    }
    rep(i, 0, N) cout << ans[i] << " \n"[i == N - 1];
}

signed main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
