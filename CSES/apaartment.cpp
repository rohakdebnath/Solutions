#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    int n, m, k; cin >> n >> m >> k;
    VI cust (n); rep(i, 0, n) cin >> cust[i];
    VI room (m); rep(i, 0, m) cin >> room[i];
    sort(all(cust));
    sort(all(room));

    int ans = 0;
    int j = 0;
    rep(i, 0, n){
        while (cust[i] - k > room[j] and j < m) ++j;
        if (room[j] >= cust[i] - k and room[j] <= cust[i] + k and j < m){
            ++ans;
            ++j;
        }
    }
    cout << ans << '\n';
    return 0;
}
