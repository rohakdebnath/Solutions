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

void solve()
{
    int n; cin >> n;
    int mini = INT32_MAX;
    int maxi = 0;
    rep(i, 0, n)
    {
        int a; cin >> a;
        mini = min(mini, a);
        maxi = max(maxi, a);
    }
    int diff = maxi - mini;
    int moves = 0;
    while (diff > 0)
    {
        diff /= 2;
        ++moves;
    }
    cout << moves << '\n';

    if (moves <= n) rep(i, 0, moves) cout << mini << ' ';
    cout << '\n';

}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
