//Heavily commented for the foundation of the doubling technique:
//Q:What is doubling?
//A: If we are supposed to apply an operator on something k times, and the operator can be nested, then we can stack our operator itself to apply multiple operations at once. Instead of calculating x_8(t) by applying x_1 8 times, we calc x_1 by itself to get x_2, then x_2 by itself to x_4 then again to form x_8.
//ex. fast exponentiation: a^k imples our operator is: multiplying a (we have to apply this on a base number = 1, k times). Note: stacking operators is simply rewriting x_{a + b}(t) = x_a(x_b(t)) (identity), where x_n is x operated n times, the identity follows trivially from the definiton of x_n.

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, k; cin >> n >> k;
    vector<int> x (n); for (int i = 0; i < n; ++i) cin >> x[i], --x[i]; //x is an operator, x[i] says index i should tranform to x[i]. 
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<int>> dp (63, vector<int> (n)); //dp[i][j] = transformation after (1 << i) operations of x on j
    //dp[i + 1][j] = dp[i][dp[i][j]];, operate x (1 << i) times on (1 << i) times operated j, to get (1 << (i + 1)) operated j
    dp[0] = x;
    for (int i = 1; i < 63; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }

    for (int i = 0; i < 63; ++i) {
        if (((1LL << i) & k) == 0) continue;
        vector<int> temp (n);
        for (int j = 0; j < n; ++j) {
            temp[j] = a[dp[i][j]];
        }
        a = std::move(temp);
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
