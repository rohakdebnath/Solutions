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
    int A, B, M; cin >> A >> B >> M;
    VI x (A); rep(0, A) cin >> x[i];
    VI y (B); rep(0, B) cin >> y[i];

    int minCost = INT32_MAX;
    while(M--)
    {
        int xt, yt, ct; cin >> xt >> yt >> ct;
        minCost = min(minCost, x[xt - 1] + y[yt - 1] - ct);
    }
    sort(all(x));
    sort(all(y));
    cout << min(minCost, x[0] + y[0]) << '\n';
    return 0;
}
