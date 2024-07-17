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
    int N, X; cin >> N >> X;
    if (N + 1 - X == X)
    {
        cout << "-1\n";
        return;
    }
    cout << X << ' ';
    rep(i, 1, N + 1)
    {
        if (i != X and i != N + 1 - X) cout << i << ' ';
    }
    cout << N + 1 - X << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
