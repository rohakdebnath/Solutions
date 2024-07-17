#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve()
{
    i64 x, y; cin >> x >> y;
    i64 p = max(x, y) - min(x, y);
    i64 pow = 1;
    while (p % 2 == 0){
        pow <<= 1LL;
        p >>= 1LL;
    }
    cout << pow << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
