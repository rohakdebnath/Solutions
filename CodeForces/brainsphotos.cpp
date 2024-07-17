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
    bool survive = true;
    rep(i, 0, n*m){
        char c; cin >> c;
        if (c == 'M' or c == 'C' or c == 'Y'){
            survive = false;
        }
    }
    cout << (survive ? "#Black&White\n" : "#Color\n");
    return 0;
}
