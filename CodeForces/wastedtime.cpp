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

int main()
{
    UNSYNC
    int n, k; cin >> n >> k;
    VI x (n), y (n);
    rep(i, 0, n) cin >> x[i] >> y[i];
    double dis = 0;
    rep(i, 1, n){
        dis += hypot(x[i] - x[i - 1], y[i] - y[i - 1]);
    }
    cout << setprecision(8) << dis/50*k << '\n';
    return 0;
}
