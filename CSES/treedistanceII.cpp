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

const int SZ = 200000;

int N; 
VI tree[SZ];
int dist[SZ];
int subtree[SZ];

int dfs(int c, int p, int depth){
    dist[c] = depth;
    subtree[c] = 1;
    for (int u: tree[c]){
        if (u == p) continue; 
        subtree[c] += dfs(u, c, depth + 1);
    }
    return subtree[c];
}

i64 ans[SZ];
void printRec(int c, int p){
    for (int u: tree[c]){
        if (u == p) continue;
        ans[u] = ans[c] + N - 2LL*subtree[u];
        printRec(u, c);
    }
    return;
}

int main()
{
    UNSYNC
    cin >> N;
    rep(i, 0, N - 1){
        int a, b; cin >> a >> b; --a, --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(0, -1, 0);
    ans[0] = accumulate(dist, dist + SZ, 0LL);
    printRec(0, -1);

    rep(i, 0, N) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
