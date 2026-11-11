#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void setIO(string name = "")
{
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

template <typename T = int>
class DSU {
private:
    vector<T> parent;
    vector<int> s;

public:
    DSU(T n) : parent(n), s(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    T find(T x) {
        while (x != parent[x]) {
            x = parent[x] = parent[parent[x]];
        }
        return x;
    }

    bool merge(T x_, T y_) {
        T x = find(x_);
        T y = find(y_);

        if (x == y) return false; 

        if (s[x] < s[y]) {
            parent[x] = y;
            s[y] += s[x];
        } else {
            parent[y] = x;
            s[x] += s[y];
        };
        return true;
    }

    bool connected(T x, T y) {
        return find(x) == find(y);
    }

    int size (int x) {
        return s[find(x)];
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    setIO("moocast");
    int n; cin >> n;
    vector<array<int, 2>> c (n);
    vector<array<int, 3>> d;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            d.push_back({(c[i][0] - c[j][0]) * (c[i][0] - c[j][0]) + (c[i][1] - c[j][1]) * (c[i][1] - c[j][1]), i, j});
        }
    }
    sort(d.begin(), d.end());
    DSU dsu (n);
    int cc = n;
    int last = 0;
    for (int i = 0; i < n * (n - 1) / 2; ++i) {
        if (dsu.merge(d[i][1], d[i][2])) {
            last = d[i][0];
            if (--cc == 1) break;
        }
    }
    cout << last << '\n';
    return 0;
}
