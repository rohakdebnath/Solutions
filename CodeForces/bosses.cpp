// TLE mp no PC
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

template <typename T = int>
class DSU { //not really dsu, it's just path compression
private:
    vector<T> parent;
    vector<int> boss;

public:
    DSU(T n) : parent(n), boss (n) {
        iota(parent.begin(), parent.end(), 0);
    }

    bool merge(T x, T y) {
        parent[x] = y;
        boss[x] = 1 + count(y); // + count(y) is actually not required as one employee has only one boss, but if the problem asked us to print us the sum of the distances form the node to all the parent routes then this code can be valid but idk didnt test it, should be cool though unless theres cycles, which interfere with the path compression since a path will not even be defined, it would be an invalid problem anyway in case of cycles, non cyclic problems with a valid employee structure just with multiple bosses should be fine
        return true;
    }

    int count(T x) {
        if (x != parent[x]) {
            boss[x] += count(parent[x]);
            parent[x] = parent[parent[x]]; // path compression
        }
        return boss[x];
    }
};

void solve() {
    int n, m; cin >> n >> m;
    DSU d (n);
    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y;
            --x, --y;
            d.merge(x, y);
        } else {
            int x; cin >> x;
            --x;
            cout << d.count(x) << '\n';
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
