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
    int maxs;

public:
    DSU(T n) : parent(n), s(n, 1) , maxs(0) {
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
            maxs = max(maxs, s[y]);
        } else {
            parent[y] = x;
            s[x] += s[y];
            maxs = max(maxs, s[x]);
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
    setIO("tractor");
    int n; cin >> n;
    vector g (n, vector<int> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    vector<array<int, 3>> a;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, -1, 0, 1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 4; ++k) {
                int nr = i + dx[k], nc = j + dy[k];
                if (nr < n and nr >= 0 and nc < n and nc >= 0 and g[i][j] >= g[nr][nc]) {
                    a.push_back({g[i][j] - g[nr][nc], n * i + j, n * nr + nc});
                }
            }
        }
    }
    DSU dsu (n * n);
    sort(a.begin(), a.end());
    vector<int> cost (n * n);
    for (auto& x: a) {
        if (dsu.size(x[1]) < n * n / 2) {
            if (dsu.merge(x[1], x[2])) {
                cost[dsu.find(x[1])] = x[0];
            }
        } 
        if (dsu.size(x[1]) >= n * n / 2) {
            cout << cost[dsu.find(x[1])] << '\n';
            return 0;
        }
    }
    return 0;
}
