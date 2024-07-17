#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve()
{
    i64 n, k, q; cin >> n >> k >> q;
    vector<i64> D (1, 0);
    rep(i, 0, k){
        i64 x; cin >> x;
        D.push_back(x);
    }
    vector<i64> B (1, 0);
    rep(i, 0, k){
        i64 t; cin >> t;
        B.push_back(t);
    }
    rep(i, 0, q){
        i64 Q; cin >> Q;
        i64 j = upper_bound(all(D), Q) - D.begin() - 1;
        if (Q == 0){
            cout << "0 ";
        } else if (Q == n){
            cout << B[k] << ' ';
        } else {
            i64 ans = B[j];
            ans +=  (Q - D[j]) * (B[j + 1] - B[j]) / (D[j + 1] - D[j]);
            cout << i64(ans) << ' ';
        }
    }
    cout << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
