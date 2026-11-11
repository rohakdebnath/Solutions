#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

// Global variables to avoid passing them in functions
vector<vector<int>> adj_global;
vector<int> pair_u_global, pair_v_global, dist_global;
int n_global;

// BFS function for Hopcroft-Karp
bool bfs() {
    queue<int> q_queue;
    for(int u = 0; u < n_global; ++u){
        if(pair_u_global[u] == -1){
            dist_global[u] = 0;
            q_queue.push(u);
        }
        else{
            dist_global[u] = INT32_MAX;
        }
    }
    dist_global[n_global] = INT32_MAX;
    while(!q_queue.empty()){
        int u = q_queue.front(); q_queue.pop();
        if(u < n_global){
            for(auto &v : adj_global[u]){
                if(pair_v_global[v] == -1){
                    if(dist_global[n_global] == INT32_MAX){
                        dist_global[n_global] = dist_global[u] + 1;
                    }
                }
                else if(dist_global[pair_v_global[v]] == INT32_MAX){
                    dist_global[pair_v_global[v]] = dist_global[u] + 1;
                    q_queue.push(pair_v_global[v]);
                }
            }
        }
    }
    return dist_global[n_global] != INT32_MAX;
}

// Iterative DFS function for Hopcroft-Karp
bool dfs(int u) {
    if(u == n_global) return true;
    for(auto &v : adj_global[u]){
        if(pair_v_global[v] == -1 || (dist_global[pair_v_global[v]] == dist_global[u] + 1 && dfs(pair_v_global[v]))){
            pair_u_global[u] = v;
            pair_v_global[v] = u;
            return true;
        }
    }
    dist_global[u] = INT32_MAX;
    return false;
}

void solve() {
    int n; cin >> n;
    n_global = n;
    vector<int> a(n); 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    
    vector<int> id(n); 
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j) { return a[i] < a[j]; }); // p[q[i]] = id[i]

    // Build adjacency list
    adj_global.assign(n, vector<int>());
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(j != i && j != id[i]){
                adj_global[i].push_back(j);
            }
        }
    }

    // Initialize pairings and distances
    pair_u_global.assign(n, -1);
    pair_v_global.assign(n, -1);
    dist_global.assign(n + 1, 0);

    // Hopcroft-Karp main loop
    while(bfs()){
        for(int u = 0; u < n; ++u){
            if(pair_u_global[u] == -1){
                dfs(u);
            }
        }
    }

    // Check if matching is perfect
    bool perfect = true;
    for(int u = 0; u < n; ++u){
        if(pair_u_global[u] == -1){
            perfect = false;
            break;
        }
    }

    if(!perfect){
        cout << "Impossible\n";
        return;
    }

    // Assign q based on matching
    vector<int> q(n);
    for(int u = 0; u < n; ++u){
        q[u] = pair_u_global[u];
    }

    // Construct permutation p
    vector<int> p(n);
    for(int i = 0; i < n; ++i){
        p[q[i]] = id[i];
    }

    // Output the result
    cout << "Possible\n";
    for(int i = 0; i < n; ++i){
        cout << p[i] + 1 << (i == n - 1 ? '\n' : ' ');
    }
    for(int i = 0; i < n; ++i){
        cout << q[i] + 1 << (i == n - 1 ? '\n' : ' ');
    }
}

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
