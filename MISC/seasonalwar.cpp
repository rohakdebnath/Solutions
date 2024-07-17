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

VVI adj;
VI component;
bitset<626> vis;
void dfs(int s){
    if (vis[s]) return;
    vis[s] = 1;
    component.push_back(s);
    for (int u: adj[s]) dfs(u);
}

int main()
{
    UNSYNC
    int n; cin >> n;
    VVI photo (n + 2, VI (n + 2));
    rep(i, 1, n + 1){
        string s; cin >> s;
        rep(j, 1, n + 1){
            photo[i][j] = s[j - 1] == '1';
        }
    }
    adj.resize(n*n + 1);
    rep(i, 1, n + 1){
        rep(j, 1, n + 1){
            if (photo[i][j]){
                rep(l, i - 1, i + 2){
                    rep(m, j - 1, j + 2){
                        if (l != i or m != j){
                            if (photo[l][m]) adj[n*(i - 1) + j].push_back(n*(l - 1) + m);
                        }
                    }
                }
            }
        }
    }
    VVI cc;
    rep(i, 1, n + 1){
        rep(j, 1, n + 1){
            if (photo[i][j] and !vis[n*(i - 1) + j]){
                dfs(n*(i - 1) + j);
                cc.push_back(component);
                component.clear();
            }
        }
    }
    cout << cc.size() << '\n';
    return 0;
}

