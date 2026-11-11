#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

vector<int> zfunc(string& s){
    int n = s.size();
    vector<int> z (n);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r){
            z[i] = min<int>(r - i, z[i - l]);
        }
        while(z[i] + i < n and s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
void solve() {
    string s; cin >> s;
    int n = s.size();

    string t = s + '#';
    reverse(t.begin(), t.end());
    t = s + t;

    auto a = zfunc(t);
    int m = 0;
    for (int i = 2 * n; i >= n + 1; --i) {
        if (a[i] == 2 * n + 1 - i) m = max(m, a[i]);
    }
    auto f = s;
    reverse(f.begin(), f.end());
    for (int i = m; i < n; ++i) {
        f += s[i];
    }
    reverse(f.begin(), f.end());
    cout << f << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
