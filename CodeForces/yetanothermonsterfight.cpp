#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int N; cin >> N;
    vector<int> A (N); for (int i = 0; i < N; ++i) cin >> A[i];
    vector<int> P (N), S (N);
    for (int i = 0; i < N; ++i) {
        P[i] = A[i] + N - 1 - i;
        S[i] = A[i] + i;
    }
    for (int i = 1; i < N; ++i) {
        P[i] = max(P[i], P[i - 1]);
    }
    for (int i = N - 2; i >= 0; --i) {
        S[i] = max(S[i], S[i + 1]);
    }
    int ans = 2e9;
    for (int i = 0; i < N; ++i) {
        int t = A[i];
        if (i > 0) t = max(t, P[i - 1]);
        if (i < N - 1) t = max(t, S[i + 1]);
        ans = min(ans, t);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; T = 1;
    while(T--) solve();
    return 0;
}
