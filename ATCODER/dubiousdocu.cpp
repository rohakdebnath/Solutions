#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i {ini}; i < x; ++i)
#define per(i, fin, x) for (int i {fin}; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int n; cin >> n;
    VVI alphagroup (n, VI (26));
    rep(i, 0, n)
    {
        string s; cin >> s;
        for(char c: s) ++alphagroup[i][c - 'a'];
    }
    VI X (26);
    rep(i, 0, 26)
    {
        int mini = INT32_MAX;
        rep(j, 0, n)
        {
            mini = min(mini, alphagroup[j][i]);
        }
        X[i] = mini;
    }
    rep(i, 0, 26)
    {
        rep(j, 0, X[i]) cout << static_cast<char>('a' + i);
    }
    cout << '\n';
}
