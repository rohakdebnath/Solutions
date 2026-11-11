#include <bits/stdc++.h>

using namespace std;
using i64 = long long;


void solve() {
    int n; cin >> n;
    map<string, int> m, mp;
    vector<string> name (n);
    vector<int> pt (n);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int x; cin >> x;
        m[s] +=x;
        name[i] = s;
        pt[i] = x;
    }
    int maxi = max_element(m.begin(), m.end(), [] (const auto& a, const auto& b) {
        return a.second < b.second;
    }) -> second;

    for (int i = 0; i < n; ++i) {
        mp[name[i]] += pt[i];
        if(m[name[i]] == maxi and mp[name[i]] >= maxi)
        {
            cout << name[i] << '\n';
            return;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
