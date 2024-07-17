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
    i64 n, P, l, t; cin >> n >> P >> l >> t;
    i64 tunlk = (n - 1)/7 + 1;
    i64 workingdays = 0;
    i64 maxidays = (P % (l + 2*t) == 0 ? P/(l + 2*t) : P/(l + 2*t) + 1);
    if (tunlk >= 2)
    {
        P -= min(maxidays, tunlk/2)*(l + 2*t);
        workingdays += min(maxidays, tunlk/2);
    }
    if (tunlk % 2 and P > 0)
    {
        P -= (l + t);
        ++workingdays;
    }
    if (P > 0) workingdays += (P%l == 0? P/l : P/l + 1);
    cout << n - workingdays << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
