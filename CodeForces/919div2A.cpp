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
    i64 N; cin >> N;
    map<i64, i64> notin;
    i64 l = 0, r = 1e9;
    rep(i, 0, N){
        i64 c; cin >> c;
        i64 p; cin >> p;
        if (c == 1){
            l = max(l, p);
        } else if (c == 2){
            r = min(r, p);
        } else {
            ++notin[p];
        }
    }
    i64 ans = r - l + 1;
    for(auto [u, v]: notin){
        if (v and (u >= l and u <= r)){
            --ans;
        }
    }
    cout << max(ans, 0LL) << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
