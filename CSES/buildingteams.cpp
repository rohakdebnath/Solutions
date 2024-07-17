//exactly same as the internal solution. But ill try to add useful comments
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
VI color;

bool dfs(int s){ // a slightly different variation of dfs, here instead of returning on a visited node, we will check if it is properly colored, as implemented as the id statement of the for loop, 
    int curr = color[s];
    int nex = (curr == 1 ? 2 : 1);
    for (int u : adj[s]){
        if (color[u]){
            if (color[u] != nex) return false;
        } else { //the else part is basically what happens when we are not returning from a pre visited node
            color[u] = nex;
            if (!dfs(u)) return false;
        }
    }
    return true;
}

int main()
{
    UNSYNC
    int n, m; cin >> n >> m;
    adj.resize(n);
    color.resize(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool bipar = true;
    rep(i, 0, n){
        if (!color[i]){
            color[i] = 1;
            if (!dfs(i)){
                bipar = false;
                break;
            }
        }
    }

    if (bipar){
        rep(i, 0, n) cout << color[i] << ' ';
        cout << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
