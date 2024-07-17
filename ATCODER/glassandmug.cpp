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
    int K, G, M; cin >> K >> G >> M;
    int glass = 0, mug = 0;
    rep(0, K)
    {
        if (glass == G) glass = 0;
        else if (mug == 0) mug = M;
        else
        {
            int space = G - glass;
            glass += min(space, mug);
            mug -= min(space, mug);
        }
    }
    cout << glass << ' ' << mug << '\n';
    return 0;
}
