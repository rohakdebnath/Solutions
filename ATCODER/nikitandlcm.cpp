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
    i64 x = 1;
    for (i64 i = 0; i < N; i++) {
        x = lcm(x, 1LL * A[i]);
        if (x > 1e9){
            break;
        }
    }
    if (find(all(A), x) == A.end()){
        cout << N << '\n';
        return;
    }
    i64 ans = 0;
    auto check = [&] (i64 d){
        if (find(all(A), d) != A.end()) return;
        i64 l = 1;
        i64 c = 0;
        rep(i, 0, N) if (d % A[i] == 0) ++c, l = lcm(l, A[i]);
        if (l == d) ans = max(ans, c);
    };
    
    for (i64 i = 1; i * i <= x; ++i){
        if (x % i == 0){
            check(i);
            check(x / i);
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
