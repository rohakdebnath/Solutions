#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 inf = 1e18;

struct State {
    int node;
    bool horsed;
    i64 time;

    bool operator<(const State& other) const {
        return time > other.time;
    }
};

vector<i64> dijkstra(int s, int n, const vector<vector<pair<int, int>>>& adj, const vector<bool>& active) {
    vector<vector<i64>> d(n, vector<i64> (2, inf));
    priority_queue<State> pq;

    if (active[s]) {
        d[s][0] = 0;
        pq.push(State{s, false, 0});

        d[s][1] = 0;
        pq.push(State{s, true, 0});
    } else {
        d[s][0] = 0;
        pq.push(State{s, false, 0});
    }

    while (!pq.empty()) {
        State current = pq.top(); pq.pop();
        int u = current.node;
        bool horsed = current.horsed;
        i64 curr = current.time;

        if (curr > d[u][horsed])
            continue;

        for (auto& [v, w] : adj[u]) {
            i64 time = horsed ? (w / 2) : (i64)w;

            if (d[v][horsed] > curr + time) {
                d[v][horsed] = curr + time;
                pq.push(State{v, horsed, d[v][horsed]});
            }

            if (active[v] and !horsed) {
                if (d[v][1] > curr + time) {
                    d[v][1] = curr + time;
                    pq.push(State{v, true, d[v][1]});
                }
            }
        }
    }


    vector<i64> mini(n, inf);
    for(int i = 0; i < n; ++i){
        mini[i] = min(d[i][0], d[i][1]);
    }
    return mini;
}

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a (h); for (int i = 0; i < h; ++i) cin >> a[i], --a[i];
    vector<bool> active(n, false);
    for(auto x : a) active[x] = true;

    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    for(int i = 0; i < m; ++i){
        int u, v, w; cin >> u >> v >> w; u--; v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<i64> distMarian = dijkstra(0, n, adj, active);
    vector<i64> distRobin = dijkstra(n-1, n, adj, active);

    i64 ans = inf;
    for(int i = 0; i < n; ++i){
        ans = min(ans, max(distMarian[i], distRobin[i]));
    }
    cout << (ans == inf ? -1: ans) << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

