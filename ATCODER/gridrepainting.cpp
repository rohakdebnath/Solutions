#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int H, W; cin >> H >> W;
    vector<vector<char>> grid (H + 2, vector<char> (W + 2, '.'));
    for(int i = 1; i <= H; ++i)
    {
        string s; cin >> s;
        for(int j = 1; j <= W; ++j)
        {
            if (s[j - 1] == '#') grid[i][j] = '#';
        }
    }
    for (int i = 1; i <= H; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            if (grid[i][j] == '#')
            {
                if (grid[i - 1][j] == '.' and grid[i + 1][j] == '.' and grid[i][j - 1] == '.' and grid[i][j + 1] == '.')
                {
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }
    cout << "Yes\n";
    return 0;
}
