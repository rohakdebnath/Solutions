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
    int n, m; cin >> n >> m;
    DSU d (n);
    while (m--) {
        string s; cin >> s;
        if (s == "union") {
            int x, y; cin >> x >> y;
            --x, --y;
            d.merge(x, y);
        } else {
            int x; cin >> x; --x;
            int e = d.find(x);
            array<int, 3> ans;
            ans[0] = d.minel(e) + 1, ans[1] = d.maxel(e) + 1, ans[2] = d.size(e);
            for (int i = 0; i < 3; ++i) {
                cout << ans[i] << " \n"[i == 3 - 1];
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

