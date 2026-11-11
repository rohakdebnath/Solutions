#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
    }
    
    vector<bool> vis(n + 1);
    i64 ans = 0;
    
    for (int i = 1; i <= n; ++i){
        if (!vis[i]){
            int len = 0, curr = i;
            while(!vis[curr]){
                vis[curr] = true;
                curr = p[curr];
                len++;
            }
            if(len >= 3){
                ans += (len - 1) / 2;
            }
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

