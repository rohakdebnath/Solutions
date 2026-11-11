#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k, q; cin >> n >> k >> q;
    vector<vector<int>> grid(k, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> grid[j][i];
        }
    }
    for (int j = 0; j < k; ++j) {
        for (int i = 1; i < n; ++i) {
            grid[j][i] |= grid[j][i - 1];
        }
    }
    vector<int> tmax(k, -1);
    vector<int> tmin(k, INT32_MAX);
    while(q--){
        int m;
        cin >> m;
        vector<int> reg;
        for(int i = 0; i < m; ++i){
            int r, c;
            char o;
            cin >> r >> o >> c;
            r -= 1;
            if(o == '>'){
                if(tmax[r] < c){
                    tmax[r] = c;
                    reg.push_back(r);
                }
            }
            else if(o == '<'){
                if(tmin[r] > c){
                    tmin[r] = c;
                    reg.push_back(r);
                }
            }
        }
        sort(reg.begin(), reg.end());
        reg.erase(unique(reg.begin(), reg.end()), reg.end());
        int rmini = 0;
        int rmaxi = n;
        bool possible = true;
        for(auto r : reg){
            if(tmax[r] != -1){
                int idx = upper_bound(grid[r].begin(), grid[r].end(), tmax[r]) - grid[r].begin();
                if(idx == n){
                    possible = false;
                    break;
                }
                rmini = max(rmini, idx);
            }
            if(tmin[r] != INT32_MAX){
                int idx = lower_bound(grid[r].begin(), grid[r].end(), tmin[r]) - grid[r].begin();
                rmaxi = min(rmaxi, idx);
            }
        }
        if (!possible or rmini >= rmaxi) cout << "-1\n";
        else cout << (rmini + 1) << "\n";
        for(auto r : reg){
            tmax[r] = -1;
            tmin[r] = INT32_MAX;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
