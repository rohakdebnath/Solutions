#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void setIO(string name = "") {
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
    setIO("mootube");
    int n, q; cin >> n >> q;
    vector<array<int, 3>> ed (n - 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, w; cin >> a >> b >> w;
        --a, --b;
        ed[i] = {w, a, b};
    }
    sort(ed.begin(), ed.end(), greater<array<int, 3>> ());

    vector<array<int, 2>> que;
    for (int i = 0; i < q; ++i) {
        int k, v; cin >> k >> v;
        que.push_back({k, v - 1});
    }
    vector<int> id (q); iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&] (int i, int j) {return que[i] > que[j];});
    sort(que.begin(), que.end(), greater<array<int, 2>> ());

    DSU dsu (n);
    vector<int> ans (q);
    int j = 0;
    for (int i = 0; i < q; ++i) {
        while (j < n - 1 and ed[j][0] >= que[i][0]) dsu.merge(ed[j][1], ed[j][2]), ++j;
        ans[id[i]] = dsu.size(que[i][1]) - 1;
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}
