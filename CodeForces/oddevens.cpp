#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    i64 n, k; cin >> n >> k;
    i64 ods = (n - 1)/2 + 1;
    if (k <= ods){
        cout << 2*k - 1 << '\n';
    } else {
        k -= ods;
        cout << 2*k << '\n';
    }
    
    return 0;
}
