#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 30;
vector<vector<vector<int>>> g (inf + 1, vector<vector<int>> (inf + 1, vector<int> (inf + 1)));
void solve() {
    string s; cin >> s;
    vector<string> name {"RUBEN", "ALBERT"};
    if (s != name[0]) swap(name[0], name[1]);
    int n; cin >> n;
    int xsum = 0;
    while (n--) {
        int i, j, k; cin >> i >> j >> k;
        xsum ^= g[i][j][k];
    }
    cout << name[!xsum] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (int i = 1; i <= inf; ++i) {
        for (int j = 1; j <= inf; ++j) {
            for (int k = 1; k <= inf; ++k) {
                vector<vector<int>> div (3, vector<int> (2));
                vector<int> s (73);
                for (int l = 1; l <= i; ++l) {
                    div[0][0] = l - 1;
                    div[0][1] = i - l;
                    for (int m = 1; m <= j; ++m) {
                        div[1][0] = m - 1;
                        div[1][1] = j - m;
                        for (int n = 1; n <= k; ++n) {
                            div[2][0] = n - 1;
                            div[2][1] = k - n;
                        
                            int xsumt = 0;
                            for (int a = 0; a < 2; ++a) {
                                for (int b = 0; b < 2; ++b) {
                                    for (int c = 0; c < 2; ++c) {
                                        xsumt ^= g[div[0][a]][div[1][b]][div[2][c]];
                                    }
                                }
                            }
                            s[xsumt] = 1;
                        }
                    }
                }
                int mex = 0;
                while (s[mex]) ++mex;
                g[i][j][k] = mex;
            }
        }
    }
    solve();
    return 0;
}
