#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

bitset<100001> visited;
VVI adjL;

void dfs(int s)
{
    if (visited[s]) return;
    visited[s] = true;

    for(auto u: adjL[s]) dfs(u);
}

int main()
{
    UNSYNC
    int n, m; cin >> n >> m;
    adjL.resize(n);

    rep(i, 0, m)
    {
        int a, b; cin >> a >> b;
        adjL[--a].push_back(--b);
        adjL[b].push_back(a);
    }
    VI cityrep;
    rep(i, 0, n)
    {
        if (visited[i]) continue;
        cityrep.push_back(i);
        dfs(i);
    }

    cout << cityrep.size() - 1 << '\n';
    rep(i, 0, cityrep.size() - 1) cout << cityrep[i] + 1 << ' ' << cityrep[i + 1] + 1 << '\n';
    return 0;
}
