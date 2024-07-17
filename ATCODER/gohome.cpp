// #include <bits/stdc++.h>

// using namespace std;
// using i64 = long long;

// #define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
// #define sci(x) static_cast<int>(x)
// #define all(x) x.begin(), x.end()
// #define rep(ini, x) for (int i {ini}; i < x; ++i)
// #define VI vector<int>
// #define VVI vector<vector<int>>

// int main()
// {
//     UNSYNC
//     i64 X; cin >> X;
//     i64 ans = ceil((static_cast<long double>(sqrt(1LL + 8*X)) - 1LL)/2.0);
//     cout << ans << '\n';
//     return 0;
// }
//writing in binary search just for practice of partition_point
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
    i64 X; cin >> X;
    i64 ans = *ranges::partition_point(ranges::iota_view(1LL, 1e5 + 1LL), [&] (i64 i)
    {
        if (i*i + i >= 2*X) return false;
        else return true;
    });
    cout << ans << '\n';
    return 0;
}
