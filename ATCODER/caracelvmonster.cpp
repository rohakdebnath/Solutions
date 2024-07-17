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
    i64 H; cin >> H;
    i64 attacks = 0;
    i64 parallelmonstcount = 1;
    while (H > 0)
    {
        attacks += parallelmonstcount * 1;
        if (H == 1) --H;
        else
        {
            H /= 2;
            parallelmonstcount *= 2;
        }
    }

    cout << attacks << '\n';
    return 0;
}
