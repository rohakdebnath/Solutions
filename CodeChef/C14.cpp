#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve() {
    i64 N, K; cin >> N >> K;
    K *= 2;
    vector<i64> a(N), h(N);
    rep(i, 0, N) cin >> a[i];
    rep(i, 0, N) cin >> h[i];

    vector<i64> mn(N + 1, (i64)1e18);
    per(i, N - 1, 0) {
        mn[i] = min(a[i] - h[i], mn[i + 1] - h[i]);
    }

    bool ps = false;
    i64 r = 0, cur = 0, curt = 0;

    rep(i, 0, N) {
        cur = a[i];
        while (r < N && a[r] <= cur + K) r++;
        if (mn[r] >= curt) ps = true;
        curt += h[i];
        if (curt > a[i]) break;
    }

    cout << (ps ? "YES\n" : "NO\n");
}

int main() {
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
