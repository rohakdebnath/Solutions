#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    i64 n, x; cin >> n >> x;
    VI a (n); rep(i, 0, n) cin >> a[i];
    VI pdx (n);
    iota(all(pdx), 0);
    sort(all(pdx), [&] (i64 i, i64 j) {return a[i] < a[j];});
    i64 p1 = 0, p2 = n - 1;
    while (p1 < p2)
    {
        if (a[pdx[p1]] + a[pdx[p2]] > x) --p2;
        else if (a[pdx[p1]] + a[pdx[p2]] < x) ++p1;
        else
        {
            cout << pdx[p1] + 1 << ' ' << pdx[p2] + 1 << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
