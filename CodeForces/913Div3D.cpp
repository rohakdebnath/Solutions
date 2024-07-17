#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

void solve()
{
    int N; cin >> N;
    VI x (N), y (N);
    rep(0, N) cin >> x[i] >> y [i];
    int minK = *ranges::partition_point(ranges::iota_view(0, 1e9 + 1),[&] (int k)
    {
        int X = 0, Y = 0;
        rep(0, N)
        {
            X -= k;
            Y += k;
            X = max(X, x[i]);
            Y = min(Y, y[i]);
            if (X > Y) return true;
        }
        return false;
    });
    cout << minK << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
