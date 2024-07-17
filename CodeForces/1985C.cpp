#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve()
{
    i64 N; cin >> N;
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    i64 s = 0, ans = 0;
    map<i64, i64> fnd;
    rep(i, 0, N){
        fnd[A[i]] = 1;
        s += A[i];
        if (s % 2) continue;
        if (fnd[s/2]) ++ans;
    }
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
