#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> vis, ancestral;
vector<int> cycle;

int dfs(int v) {
    //retuns 0, 1, 2. 0 is no cycle, 1 is cycle has ended within, 2 is remains partially with ancestors. stores the first cycle found
    vis[v] = ancestral[v] = true;
    for (int u: adj[v]) {
        if (!vis[u]) {
            int verd = dfs(u);
            if (verd == 2) {
                ancestral[v] = false;
                if (v == cycle[0]) return 1;
                else {
                    cycle.push_back(v);
                    return 2;
                }
            } else if (verd == 1) {
                ancestral[v] = false;
                return 1;
            }
        } else if (ancestral[u]) { 
            cycle.push_back(u);
            cycle.push_back(v);
            ancestral[v] = false;
            return 2;
        } 
    }
    ancestral[v] = false;
    return 0;
}

int main() {
	int n, m;
	cin >> n >> m;
	adj = vector<vector<int>>(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; --a, --b;
		adj[a].push_back(b);
	}

	vis = vector<bool> (n);
	ancestral = vector<bool> (n);
	for (int i = 0; cycle.empty() and i < n; i++) dfs(i);

	if (cycle.empty()) {
		cout << "IMPOSSIBLE" << '\n';
	} else {
		reverse(cycle.begin(), cycle.end());
		cout << cycle.size() + 1 << "\n";
		for (int node: cycle) cout << node + 1 << " ";
		cout << cycle[0] + 1 << '\n';
	}
}
