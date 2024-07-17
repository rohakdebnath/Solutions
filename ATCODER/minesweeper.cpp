#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    int H, W; cin >> H >> W;
    VVI ground (H + 2, VI (W + 2));
    for(int i = 1; i <= H; ++i)
    {
        string s; cin >> s;
        for(int j = 1; j <= W; ++j)
        {
            if (s[j - 1] == '#') 
            {
                ground[i][j] = -1;
                for (int k = i - 1; k <= i + 1; ++k)
                {
                    for (int l = j - 1; l <= j + 1; ++l)
                    {
                        if (ground[k][l] != -1) ++ground[k][l];
                    }
                }
            }
        }
    }
    for (int i = 1; i <= H; ++i)
    {
        for(int j = 1; j <= W; ++j)
        {
            if (ground[i][j] == -1) cout << '#';
            else cout << ground[i][j];
        }
        cout << '\n';
    }
    return 0;
}
