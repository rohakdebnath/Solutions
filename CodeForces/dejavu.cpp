#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

void solve()
{
    i64 n, q; cin >> n >> q;
    VI A (n); rep(i, 0, n) cin >> A[i];
    VI B (q); rep(i, 0, q) cin >> B[i];
    i64 max = 31;
    rep(i, 0, q){
        if (B[i] > max) continue;
        for(i64& x : A){
            if (x % (1 << B[i]) == 0){
                x += (1 << (B[i] - 1));
            }
        }
        max = B[i] - 1;
    }
    for(i64 i: A) cout << i << ' ';
    cout << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
