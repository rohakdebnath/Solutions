//
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

VI tree[200000];
int firstmax[200000];
int secondmax[200000];
int bestchild[200000];

void dfs (int s, int p){
    firstmax[s] = 0;
    secondmax[s] = 0;
    for (int u: tree[s]){
        if (u == p) continue;
        dfs (u, s); //This recursion is positioned early because the current subtree's calculations depend on later subtrees
        if (firstmax[u] + 1 > firstmax[s]){
            secondmax[s] = firstmax[s];
            firstmax[s] = firstmax[u] + 1;
            bestchild[s] = u;
        } else if (firstmax[u] + 1 > secondmax[s]){
            secondmax[s] = firstmax[u] + 1;
        }
    }
    return;
}

void dfs2 (int s, int p){
    for (int u : tree[s]){
        if (u == p) continue;
        if (u == bestchild[s]){
            if (secondmax[s] + 1 > firstmax[u]){
                secondmax[u] = firstmax[u];
                firstmax[u] = secondmax[s] + 1;
                bestchild[u] = s;
            } else if (secondmax[s] + 1 > secondmax[u]){
                secondmax[u] = secondmax[s] + 1;
            }
        } else {
            secondmax[u] = firstmax[u]; 
            firstmax[u] = firstmax[s] + 1; //If the child is not the best child then most definitely the max path through its parent will be more than a max path through it's child
            bestchild[u] = s;
        }
        dfs2(u, s); //This dfs is positioned later because the later subtrees calculation will depend on the upper subtrees
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
    dfs(0, -1);
    dfs2(0, -1);

    rep(i, 0, N) cout << firstmax[i] << ' ';
    cout << '\n';
    return 0;
}
