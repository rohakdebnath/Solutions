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
    vector<vector<char>> grid (H, vector<char> (W));
    rep (0, H)
    {
        string s; cin >> s;
        grid[i] = vector<char>(all(s));
    }
    vector<vector<int>> check (H, vector<int> (W));
    check[0][0] = 1;
    check[H - 1][W - 1] = 1;
    int x = 0, y = 0;
    while (x < H and y < W)
    {
        if (x == H - 1 and y == W - 1) break;
        else if (x + 1 < H and grid[x + 1][y] == '#')
        {
            ++x;
            check[x][y] = 1;
        } 
        else if (y + 1 < W and grid[x][y + 1] == '#')
        {
            ++y;
            check[x][y] = 1;
        }
        else
        {
            cout << "Impossible\n";
            return 0;
        }
    }
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (grid[i][j] == '#' and check[i][j] != 1)
            {
                cout << "Impossible\n";
                return 0;
            }
        }
    }
    cout << "Possible\n";
    return 0;
}
