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
    setIO("wormsort");
    int n, m; cin >> n >> m;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
    vector<array<int, 3>> s (m);
    for (int i = 0; i < m; ++i) {
        cin >> s[i][1] >> s[i][2] >> s[i][0];
        --s[i][1], --s[i][2];
    }
    sort(s.begin(), s.end(), greater<array<int, 3>> ());
    int j = 0;
    DSU dsu (n);
    for (int i = 0; i < n; ++i) {
        while (dsu.find(i) != dsu.find(a[i])) {
            dsu.merge(s[j][1], s[j][2]);
            ++j;
        }
    }
    cout << (j == 0 ? -1 : s[j - 1][0]) << '\n';
    return 0;
}
