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
    int n, m; cin >> n >> m;
    VI erat (2*n + 1, 1);
    for (int p = 2; p*p <= 2*n; ++p){
        if (erat[p]){
            for (int i = p * p; i <= 2*n; i += p)
            erat[i] = 0;
        }
    }
    int nexp = *(ranges::find_if(ranges::iota_view(2, 2*n + 1), [&] (int i) {
        if (erat[i] and i > n) return true;
        return false;
    }));
    cout << (nexp == m ? "YES\n": "NO\n") << '\n';
    return 0;
}
