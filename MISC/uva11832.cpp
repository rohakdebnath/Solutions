#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve(int n, int m) {
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> dp (80001, vector<int> (n, -1));
    vector<int> neg (n), pos (n);
    auto memo = [&] (auto&& self, int val, int i) ->bool {
        if (i == n) return val == m;
        if (dp[val + 16000][i] != -1) return dp[val + 16000][i];
        int ne, po; ne = po = 0; 
        if (val - a[i] + 16000 >= 0) ne = self(self, val - a[i], i + 1);
        if (val + a[i] + 16000 <= 80000) po = self(self, val + a[i], i + 1);
        if (ne) neg[i] = 1;
        if (po) pos[i] = 1;
        return dp[val + 16000][i] = (ne or po);
    };
    auto sol = memo(memo, 0, 0);
    if (!sol) {
        cout << "*\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (pos[i] and neg[i]) cout << '?';
        else if (pos[i]) cout << '+';
        else cout << '-';
    }
    cout << '\n';
}   

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int a, b;
    while(true){
        cin >> a >> b;
        if (a or b) solve(a, b);
        else break;
    } 
    return 0;
}
