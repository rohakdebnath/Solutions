//Problem insipred by "APTtest.cpp", which has n elements, a[i] <= 2000, and we want to print the count of all distinct xors of three elements.
//an array of size n is given (n <= 1e4) , each element ranging from 0 to 1e3. 4 indexes needs to be picked (repeat allowed) then sum(a[i]) to match q_j, where q queries are given (q <= 1e5)
//print if q_i can be made
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<bool>> dp (5, vector<bool> (4001)); //dp[i][j] = true if j has been built when i picks remain
    auto dfs = [&] (auto&& self, int k, int s) {
        if (dp[k][s]) return;
        dp[k][s] = 1;
        if (k == 0) return;
        for (int i = 0; i < n; ++i) {
            self(self, k - 1, s + a[i]);
        }
        return;
    };
    dfs(dfs, 4, 0);
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << dp[0][x] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

//The main idea behind these type of problems is to see that the result of xorring/summing is bounded by a fairly small number, in our case <= 4000, then we can memoise
