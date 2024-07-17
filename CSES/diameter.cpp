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

int dis = 0, e = 0;
VI tree[200000];
void dfs(int s, int p, int depth){
    for (int u: tree[s]){
        if (u != p){
            dfs(u, s, depth + 1);
        }
    }
    if (depth > dis){
        e = s;
        dis = depth;
    }
    return;
}

int main()
{
    UNSYNC
    int N; cin >> N;
    rep(i, 0, N - 1){
        int a, b; cin >> a >> b; --a, --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(0, -1, 0);
    dfs(e, -1, 0);
    cout << dis << '\n';
    return 0;
}
