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
    vector<int> z = zfunc(s);
    for (int i = n - 1; i >= 1; --i) {
        int x = z[i];
        if ((n - 3 * x) % 2 or (x == 0)) continue;
        int y = (n - 3 * x) / 2;
        if (x + y < n and z[x + y] == 2 * x + y) {
            cout << "YES\n";
            cout << (s.substr(0, 2 * x + y)) << '\n';
            return;
        }
    }
    cout << "NO\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
