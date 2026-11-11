// #include <bits/stdc++.h>

// using namespace std;
// using i64 = long long;

// void solve() {
//     double m, n; cin >> m >> n;
//     double ans = 0;    
//     //pi = (i / m) ^ n - (i - 1 / m) ^ n
//     for (double i = 1; i <= m; ++i) {
//         ans += i * (pow(i / m, n) - pow((i - 1) / m, n));
//     } 
//     cout << fixed << setprecision(10) << double(ans) << '\n';
// }

// signed main()
// {
//     ios::sync_with_stdio(false); cin.tie(nullptr);
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> id (n); iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&] (int i, int j) {return a[i] < a[j];});
    vector<int> pid (n);
    for (int i = 0; i < n; ++i) pid[id[i]] = i;

    for (int i = 0; i < n; ++i) {
        cout << id[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; ++i) {
        cout << pid[i] << " \n"[i == n - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
