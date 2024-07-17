#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

const int MAX_N = 2e5; // Max size of N
vector<vector<int>> adj(MAX_N);
vector<int> vis(MAX_N, 0);
vector<int> cc;

void dfs(int u){
    vis[u] = 1;
    cc.push_back(u);
    for(auto v : adj[u]){
        if (!vis[v]) dfs(v);
    }
}

bool adjacentelementcheck(){
    sort(all(cc));
    rep(i, 1, cc.size()){
        if (cc[i] - cc[i - 1] == 1){
            return true;
        }
    }
    return false;
}

void solve() {
    int N; cin >> N;
    fill(vis.begin(), vis.begin() + N, 0);
    cc.clear(); 
    adj.clear(); adj.resize(N);
    vector<int> A(N); 
    rep(i, 0, N) cin >> A[i];

    vector<int> id (N); iota(all(id), 0);
    sort(all(id), [&] (int i, int j) {return A[i] < A[j];});
    vector<int> pid (N);
    rep(i, 0, N) pid[id[i]] = i;

    rep(i, 0, N){
        if (i == pid[i]) continue;
        adj[i].push_back(pid[i]);
    } 
    
    int ans = 0;
    bool fnd = false; // Searching for connected components with at least two adjacent nodes
    rep(i, 0, N) {
        if (!vis[i]) {
            dfs(i);
            if (!fnd && adjacentelementcheck()) {
                ans += cc.size() - 2;
                fnd = true;
            } else {
                ans += cc.size() - 1;
            }
            cc.clear();
        }
    }
    if (!fnd) ++ans;
    cout << ans << '\n';
}


int main() {
    UNSYNC
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
