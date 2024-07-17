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
    i64 H, W; cin >> H >> W;
    if (H == 1 or W == 1)
    {
        cout << 1 << '\n';
        return 0;
    }
    i64 area = H * W;
    if (area%2 == 0) cout << area/2;
    else cout << (area+1)/2;
    cout << '\n';
    return 0;
}
