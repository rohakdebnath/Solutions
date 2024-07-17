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
    //highly stable binary search structure, incase you don't want to use ranges::partition_point with ranges::iota_view, also partition point doesnt work with fractional ranges but BS do.
    UNSYNC

    //i call this the largest leq binary search aka largest true (LTBS) in general case.
    double t; cin >> t;
    double l = 0 - 1e-14, r = t + 1e-14; // 
    while (r - l > 1e-14){ //for integers r - l > 1 works perfectly, rhs defines the continuity of the search range
        double m = l + (r - l)/2;
        if (m*m <= t){ //bs returns the largest element satisfying this predicate , in general for an LTBS the left pointer always points to true [use when the predicate divides the range into TTTFFFF etc]
            l = m;
        } else {
            r = m;
        }
    }
    cout << setprecision(15) << l << '\n';

    // there is also a smallest geq binary search (or smallest true (STBS) in general) implementation where the l pointer always points to falses, and the ans is the element at rth index instead of at lth [use when of form FFFTTTT etc.].
    return 0;
}
