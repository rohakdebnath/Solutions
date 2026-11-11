#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, q; cin >> n >> q;
    vector<vector<int>> adj (n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> p (n, -1); //p[i] = lowest uncolored ancestor of node i
    vector<int> h (n, 0);
    auto dfs = [&] (auto&& self, int v, int parent) -> void{
        p[v] = parent;

        for (int u: adj[v]) {
            if (u != parent) {
                h[u] = h[v] + 1;
                self(self, u, v);
            }
        }
    };
    dfs(dfs, 0, -1);
    vector<int> ans (n);
    // when x and up to y are colored, we will compress the path by pointing all the nodes of the path to an ancestor x, this ancestor of x is not required to be uncolored, but the nodes skipped are required to be colored
    //induction hypothesis: say by applying the function, p stores an ancestor of y such that all the elements between y and p[y] in the actual ancestor chain are all colored. now using base case (h[i] < h[x] then return i), (no rewiring done since no ancestors of i between x to y path) we can start the induction.
    //the inductive step is easily done by pointing p[y] to the return value of p[y], then returning p[y].
    //note that since the induction is true, whenever we use p[y] to the recusive call, all the nodes which are skipped due to rewiring the tree, are of no consequence since they are colored already, note that p[y] is not forced to be uncolored, but the skipped nodes due to using this p[y] are forced to be colored.
    auto ufs = [&] (auto&& self, int x, int y, int v) -> int {
        if (y == -1 or h[y] < h[x]) return y;
        if (ans[y] == 0) ans[y] = v;
         
        return p[y] = self(self, x, p[y], v);
    };
    while(q--) {
        int x, y, v; cin >> x >> y >> v;
        --x, --y;
        ufs(ufs, x, y, v);
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}


