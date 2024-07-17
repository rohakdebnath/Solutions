#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

const i64 MX = 2000001;

VI adj[MX];
int cnt[MX];
void dfs(int c, int p){
    cnt[c] = 1;
    for (int u: adj[c]){
        if (u == p) continue;
        dfs(u, c);
        cnt[c] += cnt[u];
    }
}

int main()
{
    UNSYNC
    int N; cin >> N;
    rep(i, 0, N - 1){
        int x; cin >> x;
        adj[i + 2].push_back(x);
        adj[x].push_back(i + 2);
    }
    dfs(1, -1);
    rep(i, 1, N + 1) cout << cnt[i] - 1 << ' ';
    cout << '\n';
    return 0;
}
