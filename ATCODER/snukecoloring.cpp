#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    i64 x1 = 0, y1 = 0, x2, y2, N; cin >> x2 >> y2 >> N;
    rep(0, N)
    {
        i64 x, y, a; cin >> x >> y >> a;
        if (a == 1) x1 = max(x1, x);
        else if (a == 2) x2 = min(x2, x);
        else if (a == 3) y1 = max(y1, y);
        else y2 = min(y2, y);
    }
    cout << max(0LL, x2 - x1)*max(0LL, y2 - y1) << '\n';
    return 0;
}
