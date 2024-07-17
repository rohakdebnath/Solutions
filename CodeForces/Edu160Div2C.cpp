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

int main()
{
    UNSYNC
    int m; cin >> m;
    VI digs(30);
    rep(i, 0, m)
    {
        int t, v; cin >> t >> v;
        if (t == 1){
            ++digs[v];
        }
        else{
            per(j, 29, 0){
                int x = min(digs[j], v >> j);
                v -= (x << j);
            }
            cout << (v == 0 ? "YES\n": "NO\n");
        }
    }
    return 0;
}
