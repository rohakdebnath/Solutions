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

int main()
{
    UNSYNC
    i64 a, b, x; cin >> a >> b >> x;
    i64 ans = 0;
    if (a != 0) ans = b/x - (a - 1)/x;
    else ans = b/x + 1;
    cout << ans << '\n';
    return 0;
}
