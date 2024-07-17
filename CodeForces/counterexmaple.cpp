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
    i64 l, r; cin >> l >> r;
    if (r - l < 2){
        cout << "-1\n";
        return 0;
    }
    if (l & 1){
        if (r - l >= 3){
            cout << l + 1 << ' ' << l + 2 << ' ' << l + 3 << '\n';
        } else {
            cout << "-1\n";
        }
    } else {
        cout << l << ' ' << l + 1 << ' ' << l + 2 << '\n';
    }

    return 0;
}
