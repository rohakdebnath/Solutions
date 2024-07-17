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
    i64 L, R; cin >> L >> R;
    if (R - L >= 2019)
    {
        cout << 0 << '\n';
        return 0;
    }

    i64 rem = INT64_MAX;
    for (i64 i = L; i <= R; ++i)
    {
        for (i64 j = i + 1; j <= R; ++j)
        {
            rem = min(rem, i*j % 2019);
        }
    }

    cout << rem << '\n';
    return 0;
}
