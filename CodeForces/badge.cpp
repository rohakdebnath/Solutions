#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

vector<int> adj;
vector<vector<int>> radj;
vector<int> ans;

void tails(int i){
    for (int child: radj[i]){
        if (ans[child] == -1){
            ans[child] = ans[i];
            tails(child);
        }
    }
    return;
}

void floyd(int i){
    int j = i;
    do {
        i = adj[i];
        j = adj[adj[j]];
    } while (i != j);

    do {
        ans[i] = i;
        i = adj[i];
    } while (i != j);

    do {
        tails(i);
        i = adj[i];
    } while (i != j);
}

void solve()
{
    int N; cin >> N;
    adj.resize(N);
    radj.resize(N);
    ans.resize(N, -1);
    rep(i, 0, N){
        int x; cin >> x;
        adj[i] = x - 1;
    }
    rep(i, 0, N) radj[adj[i]].push_back(i);

    rep(i, 0, N){
        if (ans[i] == -1) floyd(i);
    }

    rep(i, 0, N) cout << ans[i] + 1 << " \n"[i == N - 1];
}

int main()
{
    UNSYNC
    solve();
    return 0;
}
