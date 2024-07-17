#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int K, X; cin >> K >> X;
    int l = max(-1000000, X - K + 1);
    int r = min(1000000, X + K - 1);

    for (int i = l; i <= r; ++i) cout << i << ' ';
    cout << '\n';
    return 0;
}
