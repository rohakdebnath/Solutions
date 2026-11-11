#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    auto diff = [](const vector<int>& v1, const vector<int>& v2) -> vector<int> {
        vector<int> result(v1.size());
        transform(v2.begin(), v2.end(), v1.begin(), result.begin(), [](int a, int b) {return a - b;});
        return result;
    };

    int n, q; cin >> n >> q;
    string a, b; cin >> a >> b;
    vector<vector<int>> fa (n + 1, vector<int> (26));
    vector<vector<int>> fb (n + 1, vector<int> (26));
    for (int i = 0; i < n; ++i) {
        fa[i + 1] = fa[i];
        ++fa[i + 1][a[i] - 'a'];
        fb[i + 1] = fb[i];
        ++fb[i + 1][b[i] - 'a'];
    }

    while (q--) {
        int l, r; cin >> l >> r; --l;
        vector<int> nfa = diff(fa[r], fa[l]);
        vector<int> nfb = diff(fb[r], fb[l]);
        int need = 0;
        for (int i = 0; i < 26; ++i) {
            if (nfa[i] <= nfb[i]) need += nfa[i] - nfb[i];
        }
        cout << need << '\n';
    }

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
