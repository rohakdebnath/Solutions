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
    int n, x; cin >> n >> x;
    VI w (n); rep(i, 0, n) cin >> w[i];
    sort(all(w));

    int ans = 0;
    int j = n - 1;
    for (int i = 0; i <= j; ++i){
        while (w[i] + w[j] > x and j >= i){
            --j;
            ++ans;
        }
        if (j >= i) ++ans, --j;
    }
    cout << ans << '\n';
    return 0;
}
