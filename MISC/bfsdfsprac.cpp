#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

const int MX = 1e6;
vector<int> adj[MX];
vector<int> vis (MX);

int dfs(int n){
    int ans = 0;
    vis[n] = 1;
    for (int u: adj[n]){
        if (!vis[u]) {
            ans += dfs(u);
        }
    }
    return ans;
}


int main()
{
    UNSYNC
    
    return 0;
}
