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
    i64 N, M = 0, A = 0, R = 0, C = 0, H = 0
    ; cin >> N;
    rep(0, N)
    {
        string S; cin >> S;
        if (S[0] == 'M') ++M;
        else if (S[0] == 'A') ++A;
        else if (S[0] == 'R') ++R;
        else if (S[0] == 'C') ++C;
        else if (S[0] == 'H') ++H;
    }
    i64 ans = M*A*R + M*A*C + M*A*H + M*R*C + M*R*H + M*C*H + A*R*C +A*R*H + A*C*H + R*C*H;
    cout << ans << '\n';
    return 0;
}
