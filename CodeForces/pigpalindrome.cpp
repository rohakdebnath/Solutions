#include <bits/stdc++.h>
using namespace std;

int const N = 1000 + 20, mod = 1e9 + 7;
int n, m, ans, dp[2][N][N];
string s[N];

void add (int &a, int &b){
    a += b;
    if (a >= mod) a -= mod;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> s[i];
        s[i] = " " + s[i];
    }

    dp[1][0][n + 1] = 1;
    int o = (n + m - 2) / 2 + 2;
    for (int t = 2; t <= o; t ++){
        int jam1 = t, jam2 = n + m - t + 2;
        memset(dp[t & 1], 0, sizeof dp[t & 1]);        
        for (int i = max(1, jam1 - m); i <= min(n, jam1 - 1); i ++){
            for (int j = max(1, jam2 - m); j <= min(n, jam2 - 1); j ++){
                if (i <= j && jam1 - i <= jam2 - j && s[i][jam1 - i] == s[j][jam2 - j]){
                    bool f1 = t & 1, f2 = !f1;
                    add(dp[f1][i][j], dp[f2][i][j]);
                    add(dp[f1][i][j], dp[f2][i - 1][j]);
                    add(dp[f1][i][j], dp[f2][i][j + 1]);
                    add(dp[f1][i][j], dp[f2][i - 1][j + 1]);           
                    if (t == o) add(ans, dp[f1][i][j]);
                }
            }
        }
    }
    return cout << ans << endl, 0;    
}
