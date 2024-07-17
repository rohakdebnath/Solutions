#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i {ini}; i < x; ++i)
#define per(i, fin, x) for (int i {fin}; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    i64 A, B, X; cin >> A >> B >> X;
    i64 K = *ranges::partition_point(ranges::iota_view(1, 1e9 + 1), [&] (i64 i)
    {
        string s = to_string(i);
        i64 price = A*i + B*s.size();
        if (price <= X) return true;
        else return false;
    });
    cout << K - 1 << '\n';
    return 0;
}
