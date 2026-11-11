#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

long rearrangeStudents(vector<int>& a, vector<int>& b) {
    int n = a.size();
    map<int, int> f;
    for (int i = 0; i < n; ++i) {
        ++f[a[i]], ++f[b[i]];
    }
    for (auto& [u, v]: f) {
        if (v & 1) return -1;
        v /= 2;
    }
    for (int i = 0; i < n; ++i) --f[a[i]];
    vector<int> p;
    for (auto [u, v]: f) {
        for (int i = 0; i < abs(v); ++i) {
            p.push_back(u);
        }
    }
    long ans = 0;
    sort(p.begin(), p.end());
    for (int i = 0; i < p.size() / 2; ++i) {
        ans += p[i];
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b (n); for (int i = 0; i < n; ++i) cin >> b[i];
    cout << rearrangeStudents(a, b) << '\n';
    return 0;
}
