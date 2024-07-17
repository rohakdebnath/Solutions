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
    int H, W; cin >> H >> W;
    while(H--)
    {
        vector<char> line (W); rep(0, W) cin >> line[i];
        rep(0, W) cout << line[i];
        cout << '\n';
        rep(0, W) cout << line[i];
        cout << '\n';
    }
    return 0;
}
