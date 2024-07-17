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
    int n, t; cin >> n >> t;
    if (n == 1 and t == 10){
        cout << "-1\n";
        return 0;
    }
    cout << t;
    if (t == 10){
        rep(i, 0, n - 2) cout << 0;
    } else {
        rep(i, 0, n - 1) cout << 0;
    }
    cout << '\n';
    return 0;
}
