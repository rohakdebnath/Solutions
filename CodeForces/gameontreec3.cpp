#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, t;
    std::cin >> n >> t;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<int> match(n, -1);
    auto dfs = [&](auto &&self, int x, int p) -> void {
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            self(self, y, x);
            if (match[x] == -1 && match[y] == -1) {
                match[x] = y;
                match[y] = x;
            }
        }
    };
    dfs(dfs, 0, -1);
    
    std::queue<int> q;
    std::vector<int> vis(n);
    for (int x = 0; x < n; x++) {
        if (match[x] == -1) {
            vis[x] = 1;
            q.push(x);
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        for (auto y : adj[x]) {
            if (match[y] != -1 && !vis[match[y]]) {
                vis[match[y]] = 1;
                q.push(match[y]);
            }
        }
    }
    
    while (t--) {
        int x;
        std::cin >> x;
        x--;
        
        if (vis[x]) {
            std::cout << "Hermione\n";
        } else {
            std::cout << "Ron\n";
        }
    }
    
    return 0;
}
