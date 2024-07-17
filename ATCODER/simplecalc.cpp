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
    i64 A, B; cin >> A >> B;
    i64 count = 0;
    if (A > B)
    {
        if (A < 0 or B > 0) count += 2 + abs(abs(A) - abs(B));
        else count += 1 + abs(abs(A) - abs(B));
    }
    else
    {
        if (A >= 0) count += B - A;
        else if (B <= 0) count += B - A;
        else count += 1 + abs(abs(A) - abs(B));
    }
    cout << count << '\n';
    return 0;
}
