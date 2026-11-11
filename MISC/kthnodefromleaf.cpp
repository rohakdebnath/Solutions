#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int k, n; cin >> k >> n;
    vector<int> a ((1 << (n + 1)) - 1); 
    for (int i = 0; i < (1 << (n + 1)) - 1; ++i) 
        cin >> a[i];
    
    vector<int> vis ((1 << (n + 1)) - 1, 0);
    int sum = 0;
    auto dfs = [&] (auto&& self, int v, vector<int>& s) -> void {
        s.push_back(v);
        int left = 2 * v + 1, right = 2 * v + 2;
        bool isLeaf = true;
        
        if (left < (1 << (n + 1)) - 1 and a[left] != -1) {
            self(self, left, s);
            isLeaf = false;
        }
        if (right < (1 << (n + 1)) - 1 and a[right] != -1) {
            self(self, right, s);
            isLeaf = false;
        }

        if (isLeaf) { 
            int x = s.size() - k - 1;
            if (x >= 0 and !vis[s[x]]) {
                vis[s[x]] = 1;
                sum += a[s[x]];
            }
        }
        s.pop_back();
    };

    vector<int> path; 
    dfs(dfs, 0, path);
    cout << sum << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

