#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

void solve()
{
    i64 n, m; cin >> n >> m;
    VVI data (m, VI (n)); //prefer taking the inputs in column form rather than rows
    for (i64 i = 0; i < n; ++i) for (i64 j = 0; j < m; ++j) cin >> data[j][i];
    for (i64 i = 0; i < m; ++i) sort(all(data[i]));

    i64 count = 0;
    for (i64 i = 0; i < m; ++i)
    {
        vector<i64> temp (n);
        temp[n - 1] = data[i][n - 1];
        for(i64 j = n - 2; j >= 0; --j) temp[j] = data[i][j] + temp[j + 1];
        
        for(i64 j = 0; j < n; ++j) count += temp[j] - data[i][j] * (n - j);
    }
    cout << count << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
