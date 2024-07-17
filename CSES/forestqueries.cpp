#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

const int SIDE = 1000;

int forest[SIDE + 1][SIDE + 1];
int pref[SIDE + 1][SIDE + 1];

int main()
{
    UNSYNC
    int N, Q; cin >> N >> Q;
    rep(i, 0, N)
    {
        rep(j, 0, N)
        {
            char a; cin >> a;
            forest[i + 1][j + 1] = a == '*';
        }
    }
    rep(i, 1, N + 1)
    {
        rep(j, 1, N + 1)
        {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + forest[i][j];
        }
    }
    rep(i, 0, Q)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << pref[x2][y2] + pref[x1 - 1][y1 - 1] - pref[x1 - 1][y2] - pref[x2][y1 - 1] << '\n';
    }
    return 0;
}
