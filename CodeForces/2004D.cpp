#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void chmin(int& a, int b) {
    a = min(a, b);
}

int hid(vector<int>& indices) {
    sort(indices.begin(), indices.end());
    return indices[0] + indices[1] * (indices[1] - 1) / 2;
}
const string color = "BGRY";
const int inf = 1e9;

void solve() {
    int n, q; cin >> n >> q;
    vector<vector<int>> c (n, vector<int> (2)) ;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < 2; ++j) {
            c[i][j] = color.find(s[j]);
        }
    }
    //nearestright[i][j] is the index of such a color code (with hash = j) which is at i or its right, ///ly for nearleft
    vector<vector<int>> nearright (n, vector<int> (6)), nearleft (n, vector<int> (6));
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            nearleft[i] = vector<int> (6, -1);
        } else {
            nearleft[i] = nearleft[i - 1];
        }
        nearleft[i][hid(c[i])] = i;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1) {
            nearright[i] = vector<int> (6, n);
        } else {
            nearright[i] = nearright[i + 1];
        }
        nearright[i][hid(c[i])] = i;
    }

    while (q--) {
        int x, y; cin >> x >> y; --x, --y;
        if (x > y) swap(x, y);
        int ans = inf;
        for (int i: c[x]) {
            for (int j: c[y]) {
                if (i == j) {
                    ans = y - x;
                } else {
                    vector<int> temp = {i, j};
                    int h = hid(temp);
                    for (int z: {nearright[x][h], nearleft[y][h]}) {
                        if (z >= 0 and z < n) {
                            chmin(ans, abs(z - x) + abs(z - y));
                        }
                    }
                }
            }
        }
        cout << (ans == inf ? -1 : ans) << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
