#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    vector<int> f (3);
    for (int i = 0; i < 3; ++i) {
        cin >> f[i];
    }
    int n = accumulate(f.begin(), f.end(), 0);
    auto check = [&] (int a, int b, int c) -> bool{
        if (min({a, b, c}) < 0) return false;
        int curr = a + b + c;
        int m = max({a, b, c});
        if (m >= 3 and m == curr) return false;
        return true;
    };
    vector<char> s (n);
    for (int i = 0; i < n; ++i) {
        if (check(f[0] - 1, f[1], f[2]) and !(i - 2 >= 0 and s[i - 1] == s[i - 2] and s[i - 1] == 'a')) {
            --f[0];
            s[i] = 'a';
        } else if (check(f[0], f[1] - 1, f[2]) and !(i - 2 >= 0 and s[i - 1] == s[i - 2] and s[i - 1] == 'b')) {
            --f[1];
            s[i] = 'b';
        } else if (check(f[0], f[1], f[2] - 1) and !(i - 2 >= 0 and s[i - 1] == s[i - 2] and s[i - 1] == 'c')) {
            --f[2];
            s[i] = 'c';
        }
    }
    cout << string (s.begin(), s.end()) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
