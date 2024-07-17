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
    i64 r, D, x2000; cin >> r >> D >> x2000;
    for (int i = 1; i <= 10; ++i)
    {
        x2000 = r*x2000 - D;
        cout << x2000 << '\n';
    }

    return 0;
}
