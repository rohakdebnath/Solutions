#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

template <typename T = int>
class DSU {
private:
    vector<T> parent;

public:
    DSU(T n) : parent(n) {
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
        parent[x] = y;

        return true;
    }

    bool connected(T x, T y) {
        return find(x) == find(y);
    }

};

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i], --a[i];

    DSU dsu (n);

    for (int i = 0; i < n; ++i) {
        int next = dsu.find(a[i]);
        cout << next + 1 << " \n"[i == n - 1];
        dsu.merge(next, (next + 1) % n);
    }

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
