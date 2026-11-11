#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];

    auto pset = [&] (auto&& self, int i, vector<int>& s) -> void {
        if (i == n) {
            for (int i = 0; i < s.size(); ++i) {
                cout << s[i] << ' ';
            }
            cout << '\n';
            return;
        }
        self(self, i + 1, s);
        s.push_back(a[i]);
        self(self, i + 1, s);
        s.pop_back();

        return;
    };

    vector<int> subset;
    pset(pset, 0, subset);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
