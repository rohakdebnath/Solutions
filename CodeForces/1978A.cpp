#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve() {
    int N; cin >> N;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    cout << A[N - 1] + *max_element(all(A) - 1) << '\n';
}

signed main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
