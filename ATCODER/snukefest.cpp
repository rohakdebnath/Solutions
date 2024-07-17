#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

int main()
{
    UNSYNC
    i64 N; cin >> N;
    vector<i64> A (N); rep(i, 0, N) cin >> A[i]; sort(all(A));
    vector<i64> B (N); rep(i, 0, N) cin >> B[i]; sort(all(B));
    vector<i64> C (N); rep(i, 0, N) cin >> C[i]; sort(all(C));

    vector<i64> PA (N);
    i64 j = 0;
    rep(i, 0, N){
        while (A[j] < B[i] and j < N) ++j;
        PA[i] = j;
    }
    partial_sum(all(PA), PA.begin());
    i64 ans = 0;
    rep(i, 0, N){
        if (B[0] >= C[i]) continue;
        i64 k = PA[lower_bound(all(B), C[i]) - B.begin() - 1];
        ans += k;
    }
    cout << ans << '\n';
    return 0;
}
