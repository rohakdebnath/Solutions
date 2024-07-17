//Finding the distance from an arbitrary root to all the nodes and taking their maximum will not work because the maximum distance path may pass from the parent node too, however the maximum-distance path from any node has to end at either diameters
//Basic idea is this: the maximum distance path from each node has to end at the diameters. therefore the maximum distance from a node will be the maximum of the distance from either ends of the diameter.
//Now we need to calculate the distance from the diameter ends for each node (which is a fixed number since the path is unique in trees)
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

int dist[2][200000];
VI tree[200000];

//This dfs, along with calculating the distance from the root to all the nodes, also returns the index of the furthest node from the current node through its children
int dfs(int s, int p, int depth, int idx){ 
    dist[idx][s] = depth;
    int furthestchild = -1;
    for (int u: tree[s]){
        if (u != p){
            int farchild = dfs(u, s, depth + 1, idx);
            if (furthestchild == -1 or dist[idx][farchild] > dist[idx][furthestchild]) furthestchild = farchild;
        }
    }
    return furthestchild == -1 ? s : furthestchild; //-1 means no children, so it itself is the furthest node
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

    int diaend1 = dfs(0, -1, 0, 0);
    int diaend2 = dfs(diaend1, -1, 0, 0);
    dfs(diaend2, -1, 0, 1);

    rep(i, 0, N){
        cout << max(dist[0][i], dist[1][i]) << ' ';
    }
    cout << '\n';
    return 0;
}
