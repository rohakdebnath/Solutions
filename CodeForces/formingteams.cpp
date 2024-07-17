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
int color[100];
bitset<100> oddnode; //we will mark nodes which dont follow the rules here

void dfs(int s, int c){
    color[s] = c;
    int nex = (c == 1 ? 2 : 1);
    for (int u: adj[s]){
        if (color[u]){
            if (color[u] == c) oddnode[u] = 1;
        } else {
            dfs(u, nex);
        }
    }
}

int main()
{
    UNSYNC
    int n, m; cin >> n >> m;
    adj = VVI (n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    rep(i, 0, n){
        if (!color[i]){
            dfs(i, 1);
        }
    }
    int oddcycles = (oddnode.count() - 1)/2 + 1; //since for every odd cycle two nodes dont follow rules, we can remove one of them and keep the other, thus a half
    oddcycles += (n - oddcycles) % 2 ? 1 : 0;  
    cout << oddcycles << '\n';
    return 0;
}
