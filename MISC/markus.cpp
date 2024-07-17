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
int n, m; 
bitset<65> vis;
void dfs(int s){
    vis[s] = 1;
    for (int u: adj[s]){
        if (!vis[u]){
            if (u == s - 1 ) cout << "left ";
            else if (u == s + 1) cout << "right ";
            else if (u == s - m) cout << "forth ";
            dfs(u);
        }
    }
    return;
}
void solve()
{
    cin >> n >> m;
    adj = VVI (n*m + 1);
    vis.reset();
    VVI mat (n + 2, VI (m + 2));
    int start = -1;
    rep(i, 1, n + 1){
        rep(j, 1, m + 1){
            char c; cin >> c;
            if (c == '@'){
                start = (i - 1)*m + j;
            }
            if (c == 'H' or c == 'A' or c == 'V' or c == 'E' or c == 'I' or c == 'O' or c == '@' or c == '#'){
                mat[i][j] = 1;
            }
        }
    }

    rep(i, 1, n + 1){
        rep(j, 1, m + 1){
            if (mat[i][j]){
                if (mat[i - 1][j]){
                    adj[m*(i - 1) + j].push_back(m*(i - 2) + j);
                }
                if (mat[i][j - 1]){
                    adj[m*(i - 1) + j].push_back(m*(i - 1) + j - 1);
                }
                if (mat[i][j + 1]){
                    adj[m*(i - 1) + j].push_back(m*(i - 1) + j + 1);
                }
            }
        }
    }
    dfs(start);
    cout << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
