#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

template <typename T = int>
class DSU {
private:
    vector<T> parent;
    vector<i64> rank, s, ext;

public:
    DSU(T n) : parent(n), rank(n, 0), s(n), ext(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    T find(T x) {
        return parent[x] == x ? x : find(parent[x]); //dont use path compression
    }

    bool merge(T x_, T y_) {
        T x = find(x_);
        T y = find(y_);

        if (x == y) return false; 

        if (rank[x] < rank[y]) {
            parent[x] = y;
            ext[x] = s[y];
        } else if (rank[x] >= rank[y]) {
            parent[y] = x;
            rank[x] += (rank[x] == rank[y]);
            ext[y] = s[x];
        };
        return true;
    }
    void add (T x, int v) {
        s[find(x)] += v;
    }
    bool connected(T x, T y) {
        return find(x) == find(y);
    }
    i64 get (T x) {
        i64 p = s[x];
        if (parent[x] == x) return s[x];
        p += get(parent[x]) - ext[x];
        return p;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    DSU d (n);
    while (m--) {
        string s; cin >> s;
        if (s == "add") {
            int x, v; cin >> x >> v; --x;
            d.add(x, v);
        } else if (s == "get") {
            int x; cin >> x; --x;
            cout << d.get(x) << '\n';
        } else {
            int x, y; cin >> x >> y;
            --x, --y;
            d.merge(x, y);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

//we will not use path compression for this, instead for getting the total points, we will simply add the points from itself and its parents until we hit the root 
//whenever we reroot a set, we need to keep track of the value that was previously stored in the tree to which this rerooting is done
//then when we add points of the parents, we can subtract the value which is "not supposed" to be included in my node because those points were not originally in the set before meging.
//extra points would only get included in a node if it or it's parent got rerooted, and luckily we stored the extra points in a separate array whenever rerooting happened, so alongside adding the points of the parent, we subtract the extras rerooting for every node to get our final score
