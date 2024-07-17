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
    i64 l = accumulate(all(A), 1LL, [&] (i64 s, i64 i) {return lcm(i, s);});
    vector<i64> ans (N);
    rep(i, 0, N) ans[i] = l / A[i];
    i64 s = accumulate(all(ans), 0LL);
    rep(i, 0, N){
        if (A[i] * ans[i] <= s){
            cout << "-1\n";
            return;
        }
    }
    rep(i, 0, N) cout << ans[i] << " \n"[i == N - 1];
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
