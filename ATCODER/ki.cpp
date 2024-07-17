#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

vector<int> tree[200000];
vector<int> val;
void dfs(int c, int p){
    if (p != -1) val[c] += val[p];
    for(int u: tree[c]){
        if (u == p) continue;
        dfs(u, c);
    }
}

int main()
{
    UNSYNC
    int N, Q; cin >> N >> Q;
    val.resize(N);
    rep(i, 0, N - 1){
        int a, b; cin >> a >> b; --a, --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    rep(i, 0, Q){
        int p, x; cin >> p >> x; --p;
        val[p] += x;
    }
    dfs(0, -1);
    rep(i, 0, N) cout << val[i] << " \n"[i == N - 1];
    return 0;
}
