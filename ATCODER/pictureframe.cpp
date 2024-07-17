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
    vector<vector<char>> framed (H + 2, vector<char> (W + 2, '#'));
    for(int i = 1; i < H + 1; ++i)
    {
        for(int j = 1; j < W + 1; ++j)
        {
            cin >> framed[i][j];
        }
    }
    for(int i = 0; i < H + 2; ++i)
    {
        for(int j = 0; j < W + 2; ++j)
        {
            cout << framed[i][j];
        }
        cout << '\n';
    }
    return 0;
}
