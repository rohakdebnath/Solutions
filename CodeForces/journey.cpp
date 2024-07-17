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

VI g[100000];
double dfs(int c, int p){
    double sum = 0;
    for(int u: g[c]){
        if (u == p) continue;
        sum += dfs(u, c) + 1;
    }
    return (sum ? sum/(g[c].size() - (p != -1)) : 0);
}

int main()
{
    UNSYNC
    int N; cin >> N;
    rep(i, 0, N - 1){
        int a, b; cin >> a >> b; --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << fixed << setprecision(10) << dfs(0, -1) << '\n';
    return 0;
}
