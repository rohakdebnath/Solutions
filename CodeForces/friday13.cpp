#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s; cin >> s;
    double p; cin >> p;
    //EX[sigma(i) / n] = sigma(EX[i]) / n, EX[i] = i if i is determined, p * 1 + (1 - p) * 0 = p if '?'
    double ans = (count(s.begin(), s.end(), '?') * p + count(s.begin(), s.end(), '1')) / s.size();
    cout << fixed << setprecision(8) << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
