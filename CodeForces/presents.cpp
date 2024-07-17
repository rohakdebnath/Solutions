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
    int n; cin >> n;
    VI giftto (n); rep(i, 0, n) cin >> giftto[i], --giftto[i];
    VI giftfrom (n); rep(i, 0, n) giftfrom[giftto[i]] = i;
    rep(i, 0, n) cout << giftfrom[i] + 1 << ' ';
    cout << '\n';
    return 0;
}
