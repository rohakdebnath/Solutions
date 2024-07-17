#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

void solve()
{
    i64 n, k; cin >> n >> k;
    VI A (n); rep(i, 0, n) cin >> A[i];
    if (k >= 3){
        cout << "0\n";
        return;
    }
    sort(all(A));
    if (k == 1){
        i64 mini = A[0];
        rep(i, 1, n){
            mini = min(mini, A[i] - A[i - 1]);
        }
        cout << mini << '\n';
        return;
    }
    i64 ans = __INT64_MAX__;
    rep(i, 0, n){
        rep(j, i + 1, n){
            i64 v = A[j] - A[i];
            ans = min(ans, v);
            auto u = upper_bound(all(A), v);
            if (u == A.begin()){
                ans = min(ans, A[0] - v);
            } else {
                ans = min({ans, *u - v, v - *(u - 1)});
            }
        }
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
