#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        mp[a[i] % k].push_back(a[i] / k);
    }
    i64 od = 0, move = 0;
    for (auto& [u, v]: mp){
        sort(v.begin(), v.end());
        if (v.size() % 2) {
            ++od;
            if (od == 2) {
                cout << "-1\n";
                return;
            }
            vector<int> f, b;
            for (int i = 1; i < v.size(); i += 2) {
                f.push_back(v[i] - v[i - 1]);
            }
            for (int i = v.size() - 2; i >= 0; i -= 2) {
                b.push_back(v[i + 1] - v[i]);
            }
            partial_sum(f.begin(), f.end(), f.begin());
            partial_sum(b.begin(), b.end(), b.begin());
            int t = 1e9;
            for (int i = 0; i < v.size(); i += 2) {
                i64 cost_f = (i / 2 - 1 >= 0 && i / 2 - 1 < f.size()) ? f[i / 2 - 1] : 0;
                i64 cost_b = (v.size() / 2 - i / 2 - 1 >= 0 && v.size() / 2 - i / 2 - 1 < b.size()) ? b[v.size() / 2 - i / 2 - 1] : 0;
                t = min<i64>(t, cost_f + cost_b);
            }
            move += t;
        } else {
            for (int i = 1; i < v.size(); i += 2) {
                move += v[i] - v[i - 1];
            }
        }
    }
    cout << move << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
