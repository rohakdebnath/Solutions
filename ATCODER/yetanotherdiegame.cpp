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
    i64 x; cin >> x;
    i64 rem = x % 11;
    i64 ans = 2*(x/11);
    if (rem > 6) ans += 2;
    else if (rem > 0 and rem <= 6) ans += 1;
    cout << ans << '\n';
    return 0;
}
