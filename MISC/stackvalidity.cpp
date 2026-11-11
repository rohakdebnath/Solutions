#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e5;
void solve() {
    vector<int> lowestfactor (inf);
    for (int i = 1; i <= inf; ++i) lowestfactor[i] = i;
    for (int i = 2; i <= inf; ++i) {
        for (int j = 2 * i; j <= inf; j += i) {
            if (lowestfactor[j] != j) continue;
            lowestfactor[j] = i;
        }
    }
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> p (n); for (int i = 0; i < n; ++i) cin >> p[i];

    vector<int> s;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        s.push_back(a[i]);
        while (!s.empty() and s.back() == p[j] and j < n) {
            s.pop_back();
            ++j;
        }
    }
    if (s.size()) {
        cout << "false\n";
        int c = 0;
        for (int i = 1; i <= s.size(); ++i) {
            c += (lowestfactor[i] == i);
        }
        cout << c << '\n';
    } else {
        cout << "true\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
