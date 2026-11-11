#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    if (n % 2 == 0) {
        return;
    }
    n = (n - 1) / 2;
    vector<string> dp (n + 1);
    auto cat = [&] (auto&& self, string s, int open, int close) -> void{
        if (s.length() == 2 * n) {
            vector<string> a {"0"};
            for (int i = 0; i < 2 * n; ++i) {
                if (s[i] == '(') {
                    a.push_back("0");
                    a.push_back("0");
                } else {
                    a.push_back("null");
                    a.push_back("null");
                }
            }
            a.push_back("null");
            a.push_back("null");

            vector<string> aux {", ", "]\n"};
            cout << "[";
            for (int i = 0; i < a.size(); ++i) {
                cout << a[i] << aux[i == a.size() - 1];
            }
        }
        if (close < open) self(self, s + ')', open, close + 1);
        if (open < n) self(self, s + '(', open + 1, close);

        return;
    };
    cat(cat, "", 0, 0);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
