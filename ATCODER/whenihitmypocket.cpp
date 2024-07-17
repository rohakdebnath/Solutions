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
    i64 K, A, B; cin >> K >> A >> B;
    i64 ini = 1;
    if (B - A <= 2) cout << K + ini << '\n';
    else
    {
        ini += min(A - 1LL, K);
        K -= min(A - 1LL, K);
        ini += K/2LL*(B - A) + (K%2);
        cout << ini << '\n';
    }
    return 0;
}
