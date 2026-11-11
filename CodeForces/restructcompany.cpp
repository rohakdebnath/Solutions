#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

template <typename T = int>
class DSU {
private:
    vector<T> parent;
    vector<int> s, next;

public:
    DSU(T n) : parent(n), s(n, 1), next (n) {
        iota(parent.begin(), parent.end(), 0);
        iota(next.begin(), next.end(), 1); // next[i] = returns the nearest right element which is not a part of the set
    }

    T find(T x) {
        while (x != parent[x]) {
            x = find(parent[x]);
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

    int march (T x) {
        if (next[x] < next.size() and find(next[x]) == find(x)) next[x] = march(next[x]); 
        return next[x];
    }
};

void solve() {
    int n, k; cin >> n >> k;
    DSU d (n);

    while (k--) {
        int t, x, y; cin >> t >> x >> y;
        --x, --y;
        if (t == 1) {
            d.merge(x, y);
        } else if (t == 2) {
            int z = x;
            while (z <= y) {
                d.merge(x, z);
                z = d.march(z);
            }
        } else {
            cout << (d.connected(x, y) ? "YES\n": "NO\n");
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
