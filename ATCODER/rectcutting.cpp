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
    double W, H, x, y; cin >> W >> H >> x >> y;
    cout << setprecision (10) << W * H * 0.5 << ' ';
    if (x == W*0.5 and y == H*0.5) cout << 1;
    else cout << 0;
    cout << '\n';
    return 0;
}
