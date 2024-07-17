#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>
#define M_PI 3.14159265358979323846264338327950288


int main()
{
    UNSYNC
    int d, h, v, e; cin >> d >> h >> v >> e;
    double ans = h/(4*v/(M_PI*d*d) - e);
    if (ans > 0){
        cout << "YES\n" << ans << '\n';
    } else {
        cout << setprecision(8) << "NO\n";
    }
    return 0;
}
