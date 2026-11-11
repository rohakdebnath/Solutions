#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

template <typename T = int>
class DSU {
private:
    vector<T> parent;
    vector<int> rank, mini, maxi, s;

public:
    DSU(T n) : parent(n), rank(n, 0), mini(n), maxi(n), s(n) {
        iota(parent.begin(), parent.end(), 0);
        for (int i = 0; i < n; ++i) {
            s[i] = 1;
            mini[i] = maxi[i] = i;
        }
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

        if (rank[x] < rank[y]) {
            parent[x] = y;
            mini[y] = min(mini[y], mini[x]);
            maxi[y] = max(maxi[y], maxi[x]);
            s[y] += s[x];
        } else if (rank[x] >= rank[y]) {
            parent[y] = x;
            rank[x] += (rank[x] == rank[y]);
            mini[x] = min(mini[y], mini[x]);
            maxi[x] = max(maxi[y], maxi[x]);
            s[x] += s[y];
        };
        return true;
    }

    bool connected(T x, T y) {
        return find(x) == find(y);
    }
    int get_rank(T x) {
        return rank[find(x)];
    }
    int minel(T x) {
        return mini[find(x)];
    }
    int maxel(T x) {
        return maxi[find(x)];
    }
    int size(T x) {
        return s[find(x)];
    }
};

void solve() {
    int n, m, k; cin >> n >> m >> k;
    while (m--) {
        int u, v; cin >> u >> v;
    }
    vector<string> s (k);
    vector<int> u (k), v (k);
    for (int i = 0; i < k; ++i) {
        cin >> s[i] >> u[i] >> v[i];
        --u[i], --v[i];
    }
    reverse(s.begin(), s.end());
    reverse(u.begin(), u.end());
    reverse(v.begin(), v.end());

    DSU d (n);
    vector<string> ans;
    for (int i = 0; i < k; ++i) {
        if (s[i] == "ask") {
            if (d.connected(u[i], v[i])) ans.push_back("YES");
            else ans.push_back("NO");
        } else {
            d.merge(u[i], v[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
