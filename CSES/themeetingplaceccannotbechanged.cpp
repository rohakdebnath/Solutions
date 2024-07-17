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
    int n; cin >> n;
    vector<pair<double, double>> posspeed (n);
    rep(i, 0, n) cin >> posspeed[i].first;
    rep(i, 0, n) cin >> posspeed[i].second;
    sort(all(posspeed));

    double l = -1e-6, r = 5e8 + 1e-6;
    while (r - l > 1e-6){
        double m = l + (r - l)/2;
        double a = posspeed[0].first, b = posspeed[n - 1].first;
        rep(i, 0, n){
            double x = posspeed[i].first - m*posspeed[i].second;
            double y = posspeed[i].first + m*posspeed[i].second;
            a = max(a, x);
            b = min(b, y);
        }
        if (a > b){
            l = m;
        } else {
            r = m;
        }
    }
    cout << fixed << setprecision(7) << r << '\n';
    return 0;
}
