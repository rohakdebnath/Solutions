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
    i64 A, B, C; cin >> A >> B >> C;
    if (A % 2 == 0 or B % 2 == 0 or C % 2 == 0)
    {
        cout << 0 << '\n';
        return 0;
    }
    if (A > B) swap(A, B);
    if (B > C) swap(B, C);
    if (A > B) swap(A, B);
    cout << A*B << '\n';
    return 0;
}
