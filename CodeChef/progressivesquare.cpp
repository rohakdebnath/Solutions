#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve()
{
    i64 n, c, d; cin >> n >> c >> d;
    map<i64, i64> f;
    rep(i, 0, n * n){
        i64 x; cin >> x;
        ++f[x];
    }
    i64 a = f.begin() ->first;
    rep(i, 0, n){
        rep(j, 0, n){
            i64 cur = a + i * c + j * d;
            if (f[cur]){
                --f[cur];
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
