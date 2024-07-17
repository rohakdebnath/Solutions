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
    int A, B, C; cin >> A >> B >> C;
    if (A > B) swap(A, B);
    if (B > C) swap(B, C);
    if (A > B) swap(A, B);
    int ans = 0;
    ans += (C - A)/2 + (C - B)/2;
    A += 2*((C - A)/2);
    B += 2*((C - B)/2);
    if (A == B and B != C) ans += 1;
    else if ((A == C and A != B) or (B == C and A != B)) ans += 2;
    cout << ans << '\n';
    return 0;
}
