#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve()
{
    i64 N, x, y; cin >> N >>x >> y;
    map<pair<i64, i64>, i64> pr;
    i64 ps = 0;
    rep(i, 0, N){
        i64 a; cin >> a;
        ps += pr[{((x - a % x) % x), a % y}];
        ++pr[{a % x, a % y}];
    }
    cout << ps << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
