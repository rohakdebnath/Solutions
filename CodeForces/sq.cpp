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
    int maxx = -__INT32_MAX__, minx = __INT32_MAX__, maxy = -__INT32_MAX__, miny = __INT32_MAX__;
    rep(i, 0, 4){
        int a, b; cin >> a >> b;
        maxx = max(maxx, a);
        minx = min(minx, a);
        maxy = max(maxy, b);
        miny = min(miny, b);
    }
    cout << (maxx - minx)*(maxy - miny) << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
