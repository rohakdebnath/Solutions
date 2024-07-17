#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

struct TwoSat {
    int n;
    vector<vector<int>> e;
    vector<bool> ans;
    TwoSat(int N) : n(N), e(2 * N), ans(N) {}
    void addClause(int u, bool f, int v, bool g) { // (u == f) or (v == g) (f, g = 1 means normal, 0 means negation must be true)
        e[2 * u + !f].push_back(2 * v + g);
        e[2 * v + !g].push_back(2 * u + f);
    }
    bool satisfiable() {
        vector<int> id(2 * n, -1), dfn(2 * n, -1), low(2 * n, -1);
        vector<int> stk;
        int now = 0, cnt = 0;
        function<void(int)> tarjan = [&](int u) {
            stk.push_back(u);
            dfn[u] = low[u] = now++;
            for (auto v : e[u]) {
                if (dfn[v] == -1) {
                    tarjan(v);
                    low[u] = min(low[u], low[v]);
                } else if (id[v] == -1) {
                    low[u] = min(low[u], dfn[v]);
                }
            }
            if (dfn[u] == low[u]) {
                int v;
                do {
                    v = stk.back();
                    stk.pop_back();
                    id[v] = cnt;
                } while (v != u);
                ++cnt;
            }
        };
        for (int i = 0; i < 2 * n; ++i) if (dfn[i] == -1) tarjan(i);
        for (int i = 0; i < n; ++i) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            ans[i] = id[2 * i] > id[2 * i + 1];
        }
        return true;
    }
    vector<bool> answer() { return ans; } //returns a boolean vector as a possible solution for the 2 sat, notice that not satisfiable means 0 all, but 0 all dont mean not satisfiable
};

void solve() {
    int N; cin >> N;
    vector<vector<int>> g (3, vector<int> (N));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> g[i][j];
        }
    }
    
    TwoSat ts (N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            int x = (j + 1) % 3;
            ts.addClause(abs(g[j][i]) - 1, g[j][i] > 0, abs(g[x][i]) - 1, g[x][i] > 0);
        }
    }
    cout << (ts.satisfiable() ? "YES\n" : "NO\n");
}

signed main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
